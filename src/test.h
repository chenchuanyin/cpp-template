#ifndef CPP_TEMPLATE_TEST_H_
#define CPP_TEMPLATE_TEST_H_

#include <vector>
#include <map>

#include "absl/container/inlined_vector.h"

namespace cpp {

class Test {
 public:
  Test() {
    dict_.insert({"hi", "你好"})
  };
  std::map<std::string, std::string>& dict() const { return dict;}
 private:
  std::map<std::string, std::string> dict_;
};

}

#endif // CPP_TEMPLATE_TEST_H_
