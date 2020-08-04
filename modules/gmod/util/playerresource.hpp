
/*
 *
 *	The resource files header.
 *
 *
 */

#include "../../../framework/entitys.hpp"  // So we can use CatEntitys

namespace modules::source {

#if defined(CATHOOK_TF2)
int PRGetMaxHealth(CatEntity* player);
int PRGetClass(CatEntity* player);
#endif

}  // namespace modules::source
