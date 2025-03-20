#ifndef __VIX_SERVER_H
#define __VIX_SERVER_H

namespace vix {
class VixServer {
private:
  std::string _server_name;
  std::string _bind;
  std::string _ipv4;
  unsigned short _port;

public:
  VixServer(std::string server_name);
  ~VixServer();
  int bind(const char *bind);
  int vix_shell();
};
} // namespace vix

#endif /* __VIX_SERVER_H */