#include <string>
#include "version.hpp"

std::string GetVersion() {
  static std::string version_str = std::string("Version 0.0.1");
  return version_str;
}
