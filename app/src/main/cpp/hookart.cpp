#include <jni.h>
#include <string>
#include "log.h"
#include "xhook/xhook.h"
#include "Test.h"

static int (*thread_create)(pthread_t *thread_out, pthread_attr_t const *attr,
                            void *(*start_routine)(void *), void *arg);

static int thread_create_proxy(pthread_t *thread_out, pthread_attr_t const *attr,
                               void *(*start_routine)(void *), void *arg) {
    LOG("thread_create_proxy thread_create_proxy thread_create_proxy \n");
    return thread_create(thread_out, attr, start_routine, arg);
}

static int (*suspend_all)(const char *cause, bool long_suspend);

static int suspend_all_proxy(const char *cause, bool long_suspend) {
    LOG("suspend_all_proxy suspend_all_proxy suspend_all_proxy \n");
    return suspend_all(cause, long_suspend);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_yan_arthooktest_HookArt_hook(JNIEnv *env, jobject thiz) {
    xhook_register("libart.so", "pthread_create",
                   (void *) &thread_create_proxy, (void **) &thread_create);


    xhook_register(".*\\.so$", "_ZN3art10ThreadList10SuspendAllEPKcb",
                   (void *) &suspend_all_proxy, (void **) &suspend_all);

    xhook_enable_debug(1);
    xhook_refresh(0);

    Test().test();
}

