#include <android/log.h>

#ifndef NATIVE_HOOK_LOG
#define NATIVE_HOOK_LOG

#define LOG(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "Logger", __VA_ARGS__))

#endif // NativeHook
