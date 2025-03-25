#ifndef __VIX_CONFIG_H
#define __VIX_CONFIG_H

namespace vix {
class VixConfig {
private:
  std::string _vix_config_path;

public:
  VixConfig(std::string path);
  ~VixConfig();

  bool suck_in_configs();
};
} // namespace vix

#endif /* __VIX_CONFIG_H */