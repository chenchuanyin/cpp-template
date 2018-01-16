#include "gflags/gflags.h"
#include "glog/logging.h"

DEFINE_string(host, "127.0.0.1", "server host");
DEFINE_int32(port, 12306, "server port");

int main(int argc, char **argv) {
  FLAGS_colorlogtostderr = true;
  FLAGS_logtostderr      = true;
  LOG(INFO) << "server host:" << FLAGS_host << ", port:" << FLAGS_port;
  return 0;
}
