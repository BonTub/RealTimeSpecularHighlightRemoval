cmake_minimum_required(VERSION 3.16)
## use this to globally use C++11 with in our project
project(demo-project CXX)
set(CMAKE_CXX_STANDARD 11)
set(SpecularHighlightRemoval_DIR ../build)
# the `pkg_check_modules` function is created with this call
find_package(PkgConfig REQUIRED) 
# these calls create special `PkgConfig::<MODULE>` variables
#pkg_check_modules(OpenCV REQUIRED OPENCVPKGLIBS openCV)
#pkg_check_modules(YOUR_PKG REQUIRED IMPORTED_TARGET ya-package)
#find_package( OpenCV REQUIRED )
#set(opencv_DIR /usr/lib/x86_64-linux-gnu/cmake/opencv4 )
#include_directories( ${OpenCV_INCLUDE_DIRS} )
#find_package( opencv REQUIRED )

pkg_check_modules(OPENCV4 REQUIRED opencv4)

#find_package(SpecularHighlightRemoval REQUIRED)
#find_package(SpecularHighlightRemoval REQUIRED)

# these calls create special `PkgConfig::<MODULE>` variables
#pkg_check_modules(SpecularHighlightRemoval REQUIRED SpecularHighlightRemoval)
add_executable(demo main.cpp)

#target_link_libraries(demo PUBLIC PkgConfig::opencv SpecularHighlightRemoval)
target_link_libraries(demo SpecularHighlightRemoval ${OPENCV4_LIBRARIES})
target_include_directories(demo PUBLIC ${OPENCV4_INCLUDE_DIRS})
target_compile_options(demo PUBLIC ${OPENCV4_CFLAGS_OTHER})
