
/*
 *
 * For source engine tracing
 *
 */

#include "../../../framework/trace.hpp"
#include "../../../framework/entitys.hpp"
#include "../hacks/interfaces.hpp"
#include "../util/mathlib.hpp"

using namespace trace;
namespace modules {
namespace csgo {
namespace trace {

class FilterSight : public ITraceFilter {
   public:
    virtual bool ShouldHitEntity(C_BaseEntity* entity, int mask) {
        return entity !=
               g_IEntityList->GetClientEntity(g_IEngine->GetLocalPlayer());
    }
    TraceType_t GetTraceType() const { return TRACE_EVERYTHING; }
};
static FilterSight filter_sight;
class FilterNoPlayer : public FilterSight {
   public:
};
static FilterNoPlayer filter_terrain;

void Init() {
    // Trace line to get entity
    trace_terrain = [](const CatVector& src,
                       const CatVector& dest) -> CatVector {
        Ray_t ray;
        ray.Init(ToVector(src), ToVector(dest));
        trace_t trace_object;
        // g_ITrace->TraceRay(ray, MASK_SHOT_HULL, &filter_default,
        // &trace_object);
        g_ITrace->TraceRay(ray, MASK_SHOT, &filter_terrain, &trace_object);
        return ToCatVector(trace_object.endpos);
    };

    // Trace a line, returns the end vector and entity if hit
    trace_sight =
        [](const CatVector& src,
           const CatVector& dest) -> std::pair<CatEntity*, CatVector> {
        Ray_t ray;
        ray.Init(ToVector(src), ToVector(dest));
        trace_t trace_object;
        // g_ITrace->TraceRay(ray, MASK_SHOT_HULL, &filter_default,
        // &trace_object);
        g_ITrace->TraceRay(ray, MASK_SHOT | CONTENTS_GRATE, &filter_sight,
                           &trace_object);
        return {(CatEntity*)trace_object.m_pEntityHit,
                ToCatVector(trace_object.endpos)};
    };
}

}  // namespace trace
}  // namespace csgo
}  // namespace modules
