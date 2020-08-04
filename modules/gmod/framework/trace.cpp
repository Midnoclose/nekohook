
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
namespace modules::source::trace {

class FilterSight : public ITraceFilter {
   public:
    virtual bool ShouldHitEntity(IHandleEntity* entity, int mask) {
        if (!entity) return false;
        // Ignore invisible entities that we don't wanna hit
        switch (((IClientEntity*)entity)->GetClientClass()->m_ClassID) {
            // TODO magic numbers: invisible entity ids
            case 64:
            case 225:
            case 55:
                return false;
        }
        // Do not hit yourself. Idiot.
        IClientEntity* raw_entity =
            g_IEntityList->GetClientEntity(g_IEngine->GetLocalPlayer());
        if (raw_entity && entity == raw_entity) return false;
        return true;
    }
    TraceType_t GetTraceType() const { return TRACE_EVERYTHING; }
};
static FilterSight filter_sight;
class FilterNoPlayer : public FilterSight {
   public:
    virtual bool ShouldHitEntity(IHandleEntity* entity, int mask) {
        if (!entity) return false;
        // Ignore invisible entities that we don't wanna hit
        switch (((IClientEntity*)entity)->GetClientClass()->m_ClassID) {
            // TODO magic numbers: invisible entity ids
            case 64:
            case 225:
            case 55:
            case 241:
                return false;
        }
        // Do not hit yourself. Idiot.    return true;
        IClientEntity* raw_entity =
            g_IEntityList->GetClientEntity(g_IEngine->GetLocalPlayer());
        if (raw_entity && entity == raw_entity) return false;
        return true;
    }
};
static FilterNoPlayer filter_terrain;

void Init() {
    // Trace line to get entity
    trace_terrain = [](CatVector src, CatVector dest) -> CatVector {
        Ray_t ray;
        ray.Init(ToVector(src), ToVector(dest));
        trace_t trace_object;
        // g_ITrace->TraceRay(ray, MASK_SHOT_HULL, &filter_default,
        // &trace_object);
        g_ITrace->TraceRay(ray, MASK_SHOT, &filter_terrain, &trace_object);
        return ToCatVector(trace_object.endpos);
    };

    // Trace a line, returns the end vector and entity if hit
    trace_sight = [](CatVector src,
                     CatVector dest) -> std::pair<CatEntity*, CatVector> {
        Ray_t ray;
        ray.Init(ToVector(src), ToVector(dest));
        trace_t trace_object;
        // g_ITrace->TraceRay(ray, MASK_SHOT_HULL, &filter_default,
        // &trace_object);
        g_ITrace->TraceRay(ray, MASK_SHOT | CONTENTS_GRATE, &filter_sight,
                           &trace_object);
        return {(CatEntity*)trace_object.m_pEnt,
                ToCatVector(trace_object.endpos)};
    };
}

}  // namespace modules::source::trace
