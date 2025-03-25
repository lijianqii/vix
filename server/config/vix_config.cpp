#include <string>

#include <glog/logging.h>
#include <rapidjson/document.h>

#include "vix_config.hpp"

vix::VixConfig::VixConfig(std::string path) {
    this->_vix_config_path = path;
}

vix::VixConfig::~VixConfig() {

}

bool vix::VixConfig::suck_in_configs() {
    return true;
}