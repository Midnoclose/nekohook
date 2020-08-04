
/*
 * Nekohook: Free, fast and modular cheat software
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

#pragma once

#include <chrono>

namespace nekohook {

template<typename Clock = std::chrono::steady_clock>
class Timer {
private:
    std::chrono::time_point<Clock> last_time;
public:
    void Reset() { this->last_time = Clock::now(); }
    typename Clock::duration GetDuration() const { return Clock::now() - this->last_time; }
    bool Check(typename Clock::duration dur) const { return this->GetDuration() > dur; }
    bool ResetCheck(typename Clock::duration dur) {
        auto ret = this->Check(dur);
        if (ret) Reset();
        return ret;
    }
};

}
