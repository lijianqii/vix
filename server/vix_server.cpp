#include <cstddef>
#include <glog/logging.h>
#include <iostream>
#include <regex>
#include <string>

#include "vix_config.hpp"
#include "vix_server.hpp"

vix::VixServer::VixServer(std::string server_name) {
  this->_server_name = server_name;

  FLAGS_logtostdout = true;
  FLAGS_colorlogtostdout = true;
  google::InitGoogleLogging(this->_server_name.c_str());

  LOG(INFO) << "Server(" << this->_server_name << "): Initializing.";
}

int vix::VixServer::bind(const char *bind) {
  this->_bind = std::string(bind);
  size_t pos = this->_bind.find(':');
  this->_ipv4 = this->_bind.substr(0, pos);
  this->_port = std::stoi(this->_bind.substr(pos + 1, this->_bind.length()));

  LOG(INFO) << "Bind address: " << this->_ipv4;
  LOG(INFO) << "Bind port: " << this->_port;

  if (this->_port >= 1 && this->_port < 1023) {
    LOG(WARNING) << "Port " << this->_port << " may need ROOT to bind.";
  }

  std::regex ipv4_regex(R"(^((?:0|(1\d{2}|2[0-4]\d|25[0-5]|[1-9]\d?))\.){3}(?:0|(1\d{2}|2[0-4]\d|25[0-5]|[1-9]\d?))$)");

  bool match = std::regex_match(this->_ipv4, ipv4_regex);
  if (match) {
    LOG(INFO) << "Legal ipv4 address";
  } else {
    LOG(ERROR) << "Inlegal ipv4 address, check it";
  }
  return 0;
}

int vix::VixServer::vix_shell() {
  std::string unused;
  std::getline(std::cin, unused);
  return 0;
}

vix::VixServer::~VixServer() { google::ShutdownGoogleLogging(); }
