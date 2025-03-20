#include <string>
#include "vix_server.hpp"

int main(int, char **) {
  vix::VixServer server("vix");

  server.bind("127.0.0.1:12345");
  return server.vix_shell();
}
