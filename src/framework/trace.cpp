
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

#include "trace.hpp"

namespace trace {

// Trace line, returns end of trace
cat::Function<CatVector(const CatVector&, const CatVector&)> Terrain{
    [](const CatVector&, const CatVector& dest) -> auto {return dest;
}  // namespace trace
}
;

// Trace a line, returns entity hit or end of trace
cat::Function<std::pair<CatEntity*, CatVector>(const CatVector&, const CatVector&, CatEntity*)>
    Shot{[](const CatVector&, const CatVector& dest,
            CatEntity* ignore) -> std::pair<CatEntity*, CatVector> {
        return {nullptr,
                dest};  // Return dest to make everything think vis check worked
    }};
}
