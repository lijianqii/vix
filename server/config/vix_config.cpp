#include <iostream>
#include <fstream>
#include <regex>
#include <string>

#include <glog/logging.h>
#include <rapidjson/document.h>

#include "vix_config.hpp"

vix::VixConfig::VixConfig() {
}

vix::VixConfig::~VixConfig() {
    LOG(INFO) << "Config: " << this->_vix_config_path << " released.";
}

unsigned short vix::VixConfig::get_port() {
    unsigned int port = this->_config_json.FindMember("port")->value.GetUint();
    if (port >= 1 && port < 1023) {
        LOG(WARNING) << "Port " << port << " may need ROOT to bind.";
    } else if (port > (unsigned short)-1) {
        LOG(WARNING) << "Port " << port << " is inlegal, change to default: 12345.";
        port = 12345;
    } else {
        LOG(INFO) << "Port: " << port << ".";
    }
    return port;
}

std::string vix::VixConfig::get_ipv4() {
    std::string address = this->_config_json.FindMember("bind address")->value.GetString();

    std::regex ipv4_regex(
        R"(^((?:0|(1\d{2}|2[0-4]\d|25[0-5]|[1-9]\d?))\.){3}(?:0|(1\d{2}|2[0-4]\d|25[0-5]|[1-9]\d?))$)");
  
    bool match = std::regex_match(address, ipv4_regex);
    if (match) {
      LOG(INFO) << "Legal ipv4 address: " << address;
    } else {
      LOG(ERROR) << "Inlegal ipv4 address,change to default: 127.0.0.1";
    }

    return address;
}

bool vix::VixConfig::suck_in_configs(const char *path) {
    std::string config_buf;
    std::ifstream if_config = std::ifstream(path);
    if (!if_config.fail()) {
        this->_vix_config_path = path;
    } else {
        std::string default_config("../configs/default_configs.json");
        LOG(WARNING) << "Config file not found, reading: " << default_config;
        if_config.open(default_config);
        if (if_config.fail()) {
            LOG(FATAL) << "NO configuration found, checkit";
        } else {
            this->_vix_config_path = default_config;
        }
    }

    while (!if_config.eof()) {
        char buf[1024] = {0};
        if_config.getline(buf, 1024);
        config_buf.append(buf);
    }

    if_config.close();

    this->_config_json.Parse(config_buf.c_str());
    return true;
}