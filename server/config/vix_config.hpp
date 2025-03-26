#ifndef __VIX_CONFIG_H
#define __VIX_CONFIG_H

#include <rapidjson/document.h>
namespace vix {
class VixConfig {
private:
  std::string _vix_config_path;
  rapidjson::Document _config_json;

public:
  VixConfig(std::string path);
  ~VixConfig();

  bool suck_in_configs();
  unsigned short get_port();
  std::string get_ipv4();
};
} // namespace vix

#endif /* __VIX_CONFIG_H */