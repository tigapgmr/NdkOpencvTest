#include <jni.h>
#include "process.hpp"
using namespace cv;
extern "C"
JNIEXPORT void JNICALL
Java_com_example_tigrammer_ndkopencvtest_MainActivity_GetGrayImage(
        JNIEnv *env, jobject, jlong inputAddr, jlong resultAddr){
    Mat &input = *(Mat*)inputAddr;
    *(Mat*) resultAddr = ConvertImage(input);
}