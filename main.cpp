#include "vix_server.hpp"

int main(int argc, char *argv[]) {
  vix::VixServer server("vix");

  if (argc < 2) {
    server.bind("default");
  } else {
    server.bind(argv[1]);
  }
  
  return server.vix_shell();
}
