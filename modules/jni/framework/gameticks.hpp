
/*
 *
 * Our main bridge to connect with the java games world ticks
 * You should call this in your java program
 *
 */

#include "../../../framework/gameticks.hpp"
#include "jni.hpp"

namespace modules::jni {

// TODO, find proper names that we should use
void JavaWorldtick(JNIEnv* env, jobject) {
    g_Enviroment = env;
    wtick();
}
void JavaDraw(JNIEnv* env, jobject) {
    g_Enviroment = env;
    drawmgr();
}

}  // namespace modules::jni
