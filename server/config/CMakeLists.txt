add_library(vix_config SHARED vix_config.cpp)

set_target_properties(vix_config PROPERTIES POSITION_INDEPENDENT_CODE ON)

find_package(glog REQUIRED)

target_include_directories(vix_config PUBLIC .)

target_link_libraries(vix_config glog::glog)