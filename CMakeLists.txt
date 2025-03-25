cmake_minimum_required(VERSION 3.10.0)
project(vix VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/output/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/output/libs)

set(CMAKE_INSTALL_RPATH "../libs")  # 可执行文件上一级的 lib 目录
set(CMAKE_BUILD_RPATH "${LIBRARY_OUTPUT_PATH}")  # 构建时的路径

#禁用默认的 RPATH 行为
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_subdirectory(./server)

find_package(glog REQUIRED)

add_executable(vix main.cpp)
target_link_libraries(vix glog::glog)
target_link_libraries(vix vix_server)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
