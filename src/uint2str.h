#include <stdio.h>

#include <sstream>
#include <string>

std::string uint2str(unsigned int num) {
  std::ostringstream oss;
  oss << num;
  return oss.str();
}

std::string uint2str2(unsigned int num) {
  char buf[32];
  sprintf(buf, "%d", num);
  return std::string(buf);
}
