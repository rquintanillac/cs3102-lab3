#include <gtest/gtest.h>

#include <iostream>
#include <thread>

#include "AVLThreadsafe.hpp"
#include "Point.h"
#include "utils/DataGenerator.hpp"

using namespace utec::concurrency;

using data_t = double;
using point_t = Point<data_t, 1>;

TEST(ConcurrencyTest, BasicTest) {
  const auto processor_count = std::thread::hardware_concurrency();

  std::thread thread_pool[processor_count];

  const std::size_t num_points = 10000;
  const data_t min = 0, max = 1000;

  DataGenerator1D<data_t> generator(num_points, min, max);
  auto points = generator.get_data();

  AVLThreadSafe<point_t> instancia;

  for (std::size_t proc_idx = 0; proc_idx < processor_count; proc_idx++) {
    thread_pool[proc_idx] = std::thread([&] {
      std::size_t chunk = num_points / processor_count;

      for (std::size_t item_idx = proc_idx * chunk;
           item_idx < (proc_idx + 1) * chunk; item_idx++) {
        EXPECT_TRUE(instancia.insert(points[item_idx]));
      }
    });
  }

  for (std::size_t proc_idx = 0; proc_idx < processor_count; proc_idx++) {
    thread_pool[proc_idx].join();
  }

  EXPECT_EQ(instancia.getNumKeys(), num_points);
  EXPECT_EQ(instancia.getMaxHeight(), 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}