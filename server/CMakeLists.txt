add_subdirectory(./config)

add_library(vix_server SHARED vix_server.cpp)

set_target_properties(vix_server PROPERTIES POSITION_INDEPENDENT_CODE ON)

find_package(glog REQUIRED)

target_include_directories(vix_server PUBLIC .)

target_link_libraries(vix_server glog::glog)
target_link_libraries(vix_server vix_config)