add_library(vix_server vix_server.cpp)

find_package(glog REQUIRED)

target_include_directories(vix_server PUBLIC .)

target_link_libraries(vix_server glog::glog)