#include <glog/logging.h>

void bar(int x) { CHECK_EQ(x, 1); }

void foo(int x) { bar(x + 1); }

int main(int argc, char **argv) {
  google::InstallFailureSignalHandler();
  foo(1);
}
