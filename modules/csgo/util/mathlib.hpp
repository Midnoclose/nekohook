
/*
 *
 *	Helpers for math conversion between the framework and the module
 *
 */

#include "../../../util/mathlib.hpp"  // CatVector()
#include "../sdk/sdk.h"               // Vector()

inline CatVector ToCatVector(const Vector& input) {
    return CatVector(input.x, input.y, input.z);
}

inline CatVector ToCatVector(const QAngle& input) {
    return CatVector(input.x, input.y, input.z);
}

inline Vector ToVector(const CatVector& input) {
    return Vector(input.x, input.y, input.z);
}

inline Vector ToVector(const QAngle& input) {
    return Vector(input.x, input.y, input.z);
}

inline QAngle ToQAngle(const CatVector& input) {
    return QAngle(input.x, input.y, input.z);
}

inline QAngle ToQAngle(const Vector& input) {
    return QAngle(input.x, input.y, input.z);
}
