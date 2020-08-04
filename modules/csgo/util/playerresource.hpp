
/*
 *
 *	The resource files header.
 *
 *
 */

#include "../../../framework/entitys.hpp"  // So we can use CatEntitys

namespace modules {
namespace source {

#if defined(CATHOOK_TF2)
int GetMaxHealth(const CatEntity& player);
int GetClass(const CatEntity& player);
#endif

}  // namespace source
}  // namespace modules
