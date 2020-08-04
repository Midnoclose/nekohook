
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

#include "entitys.hpp"

cat::Function<bool(CatEntity*)> GetDormant{[](auto) -> auto {return true;
}
}
;
cat::Function<bool(CatEntity*)> GetAlive{[](auto) -> auto {return true;
}
}
;
cat::Function<int(CatEntity*)> GetHealth{[](auto) -> auto {return 100;
}
}
;
cat::Function<int(CatEntity*)> GetMaxHealth{[](auto) -> auto {return 100;
}
}
;
cat::Function<ent::Team(CatEntity*)> GetTeam;
cat::Function<ent::Type(CatEntity*)> GetType;
cat::Function<const char*(CatEntity*)> GetName{
    [](auto) -> auto {return "unknown";
}
}
;
cat::Function<CatVector(CatEntity*)> GetOrigin;
cat::Function<CatBox(CatEntity*)> GetCollision;
cat::Function<int32_t(CatEntity*)> GetSteamId;
cat::Function<bool(CatEntity*, ent::Bone, CatBox&)> GetBone;

cat::Function<void(CatEntity*)> Attack;
cat::Function<void(CatEntity*)> Jump;
cat::Function<void(CatEntity*, CatVector)> WalkTo;
cat::Function<bool(CatEntity*)> InThirdperson;
cat::Function<CatVector(CatEntity*)> GetCamera;
cat::Function<CatVector(CatEntity*)> GetCameraAngle;
cat::Function<void(CatEntity*, const CatVector&)> SetCameraAngle;
cat::Function<void(CatEntity*, const CatVector&)> SetSilentCameraAngle;

cat::Function<int()> GetEntityCount;
cat::Function<CatEntity*(int)> GetEntity;
cat::Function<CatEntity*()> GetLocalPlayer;
