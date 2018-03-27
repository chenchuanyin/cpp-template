#include "benchmark/benchmark.h"

#include <fstream>
#include <iostream>

class Test {
 public:
  Test() {
    outfile.open("test.txt", std::ios::app);
    outfile << "Test";
  }
  ~Test() {
    outfile << "\n" << std::flush;
    outfile.close();
  }

 private:
  std::ofstream outfile;
};

static void BM_construct_destruct(benchmark::State &state) {
  for (auto _ : state) {
    Test t;
  }
}

BENCHMARK(BM_construct_destruct);

BENCHMARK_MAIN();
