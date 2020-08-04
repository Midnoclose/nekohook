
#pragma once

#include <jni.h>

// This is our main interface what we will use for everything when communicating
// with java Only use this when you dont have a env argument passed to you by
// the jvm to prevent segfaults maybe... Also please check for nullptr or face
// your doom in eternal segfaults This will be updated on events, if async you
// better hope that u wont die.
extern JNIEnv* g_Enviroment;
