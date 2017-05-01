#include <jni.h>
#include <string>
#include "test.hpp"


extern "C" {
JNIEXPORT jstring JNICALL
Java_com_example_tigrammer_ndkopencvtest_MainActivity_stringFromJNI(
        JNIEnv *env, jobject) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
JNIEXPORT jint JNICALL
Java_com_example_tigrammer_ndkopencvtest_MainActivity_intFromJNI(
        JNIEnv *env, jobject, jint num1, jint num2) {
    return getValue(num1, num2);
}

}