#include "vix_server.hpp"

int main(int argc, char *argv[]) {
  vix::VixServer server("vix");

  server.bind("default");
  return server.vix_shell();
}
