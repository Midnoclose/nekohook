
/*
 *
 *	Helpers for math conversion between the framework and the module
 *
 */

#pragma once
#include "../../../util/mathlib.hpp"  // CatVector()
#include "../sdk/sdk.hpp"             // Vector()

inline CatVector ToCatVector(Vector input) {
    return CatVector(input.x, input.y, input.z);
}

inline Vector ToVector(CatVector input) {
    return Vector(input.x, input.y, input.z);
}
