#프로젝트 및 OpenCV 라이브러리 경로를 각각 변수에 저장합니다.
# 주의!! : 본인의 프로젝트 경로와, opencv 경로로 수정합니다.
set(pathOpenCv C:/opencv/OpenCV-android-sdk_310)
set(pathProject C:/Android/AndroidStudioProjects/NdkOpencvTest)

cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

#헤더파일 경로
include_directories(${pathOpenCv}/sdk/native/jni/include)

add_library( lib_opencv SHARED IMPORTED )
set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${pathProject}/app/src/main/JniLibs/${ANDROID_ABI}/libopencv_java3.so)

file(GLOB Library_SOURCES src/main/cpp/*.cpp)
file(GLOB Library_HEADERS src/main/cpp/*.hpp)

add_library(imported-lib SHARED  ${Library_SOURCES} ${Library_HEADERS} )
set_target_properties(imported-lib PROPERTIES LINKER_LANGUAGE CXX)

add_library( native-lib
             SHARED
             src/main/cpp/native-lib.cpp )


#android log
find_library( android-lib android)

#미리 빌드된 라이브러리를 찾습니다.
find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# 타겟 라이브러리를 생성하기 위해 필요한 라이브러리를 명시합니다.
target_link_libraries( imported-lib  #타겟 라이브러리
                       lib_opencv)   #필요한 라이브러리

target_link_libraries( native-lib #타겟 라이브러리

                       #필요한 라이브러리
                       ${log-lib}
                       imported-lib
                       lib_opencv )