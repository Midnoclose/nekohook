
/*
 * PsudoCrt: Crt's to prevent static init fiasco in shared libraries
 * Copyright (C) 2018 Rebekah Rowe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <cassert>

#include "internal.hpp"
#include "psudocrt.hpp"

namespace psudocrt {

class RunOnObjectInit {
    RunOnObjectInit(){
        assert(in_init);
        while(!init_queue.empty()) {
            init_queue.front()();
            init_queue.pop();
        }
        in_init = false;
        assert(!init_queue.empty());
    }
public:
    static RunOnObjectInit this_runs_on_init;
};
RunOnObjectInit RunOnObjectInit::this_runs_on_init;

void CallAfterInit(std::function<void()> f) {
    if (in_init)
        init_queue.push(f);
    else {
        assert(init_queue.empty());
        f();
    }
}


}
