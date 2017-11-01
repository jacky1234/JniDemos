#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include "native-lib.h"
#include <android/log.h>

const char *MESSAGE = "hello from jni";

jstring Java_com_jack_jnidemo_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz,
                                                 jstring str) {
    const char *question = env->GetStringUTFChars(str, JNI_FALSE);
    const char *answer = "fuck,no why!!!";

    char *data = (char *) malloc(strlen(question) + strlen(answer) + 1);
    strcpy(data, question);
    strcat(data, "JNI说:");
    strcat(data, answer);
#ifdef Debug
    LOGE("我在hi_jni.cpp里面和你撩呢!");
# endif
    return env->NewStringUTF(data);
}


// 定义调用java中的方法的函数
void callJavaMethod(JNIEnv *env, jobject thiz) {
    // 先找到要调用的类
    jclass clazz = env->FindClass("com/jack/jnidemo/MainActivity");
    if (clazz == NULL) {
        printf("找不到要调用方法的所属类");
        return;
    }
    // 获取java方法id
    // 参数二是调用的方法名,  参数三是方法的签名
    jmethodID id = env->GetStaticMethodID(clazz, "methodCalledByJni", "(Ljava/lang/String;)V");
    if (id == NULL) {
        LOGE("找不到要调用方法");
        return;
    }
    jstring msg = env->NewStringUTF(MESSAGE);
    // 开始调用java中的静态方法
    env->CallStaticVoidMethod(clazz, id, msg);
}

void Java_com_jack_jnidemo_MainActivity_callJNIConvertJavaMethod(JNIEnv *env, jobject thiz) {
    LOGE("Java_com_jack_jnidemo_MainActivity_callJNIConvertJavaMethod");
    callJavaMethod(env, thiz);
}


