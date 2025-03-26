#include <glog/logging.h>
#include <iostream>
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
  this->_config = new vix::VixConfig(bind);

  this->_port = this->_config->get_port();
  this->_ipv4 = this->_config->get_ipv4();

  LOG(INFO) << "Bind address: " << this->_ipv4;
  LOG(INFO) << "Bind port: " << this->_port;

  return 0;
}

int vix::VixServer::vix_shell() {
  std::string unused;
  std::getline(std::cin, unused);
  std::cout << unused << std::endl;
  return 0;
}

vix::VixServer::~VixServer() {
  LOG(INFO) << "Server(" << this->_server_name << "): Closing.";
  delete this->_config;
  google::ShutdownGoogleLogging();
}
