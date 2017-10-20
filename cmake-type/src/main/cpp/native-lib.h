

#define LOG_TAG "来自jni:"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

extern "C" {
    JNIEXPORT jstring JNICALL
    Java_com_jack_jnidemo_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz, jstring str);

    void Java_com_jack_jnidemo_MainActivity_callJNIConvertJavaMethod(JNIEnv *env, jobject thiz);
}
