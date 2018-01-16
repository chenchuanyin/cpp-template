#include "uint2str.h"

#include "benchmark/benchmark.h"

static void BM_uint2str(benchmark::State &state) {
  unsigned int num = 1234;
  while (state.KeepRunning()) {
    uint2str(num);
  }
}

static void BM_uint2str2(benchmark::State &state) {
  unsigned int num = 1234;
  while (state.KeepRunning()) {
    uint2str2(num);
  }
}

static void BM_uint2str3(benchmark::State &state) {}

BENCHMARK(BM_uint2str);
BENCHMARK(BM_uint2str2);

BENCHMARK_MAIN()
