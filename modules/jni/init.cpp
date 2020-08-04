
/*
 *
 * Init for jni module
 *
 */

#include "../../util/logging.hpp"  // So we can log
#include "framework/jni.hpp"  // So we can determine if we are in a java enviroment

namespace modules::jni {

void Init() { debug_log.log("Begin JNI module init..."); }

}  // namespace modules::jni
