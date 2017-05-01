#프로젝트 및 OpenCV 라이브러리 경로를 각각 변수에 저장합니다.
#예시 : set(pathProject C:/Android/AndroidProjects/NdkOpencvTest)
set(pathProject C:/Android/AndroidProjects/NdkOpencvTest)

cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# 다음은 최대최적화 옵션을 직접 지정하는 부분입니다. 필요에 따라 작성하세요.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

#다음4줄을 추가합니다.
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

# native-lib을 컴파일 하기 위해 필요로 만든 imported-lib를 지정합니다.
target_link_libraries( native-lib #타겟 라이브러리

                       #필요한 라이브러리
                       ${log-lib}
                       imported-lib )