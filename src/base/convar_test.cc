#include "gtest/gtest.h"

#include "convar.h"
#include "mutex.h"

#include <thread>

TEST(ConVar, SignalAllTest) {
  base::Mutex  m;
  base::ConVar con(m);
  std::thread  t1([&con]() {
    con.Wait();
    std::cout << "waited" << std::endl;
  });
  std::thread  t3([&con]() {
    con.Wait();
    std::cout << "waited 2" << std::endl;
  });
  std::thread  t2([&con]() {
    sleep(1);
    con.SignalAll();
  });
  t1.join();
  t3.join();
  t2.join();
}

TEST(ConVar, SignalTest) {
  base::Mutex  m;
  base::ConVar con(m);
  std::thread  t1([&con]() {
    con.Wait();
    std::cout << "waited" << std::endl;
  });
  std::thread  t2([&con]() {
    sleep(1);
    con.Signal();
  });
  t1.join();
  t2.join();
}
