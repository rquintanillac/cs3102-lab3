#include <benchmark/benchmark.h>

#include "../tests/utils/DataGenerator.hpp"
#include "DataGenerator.hpp"
#include "Point.h"

using namespace utec::concurrency;

using data_t = double;
using point_t = Point<data_t, 1>;

// TODO
// class SetUp {
//  private:
//   SetUp() {
//     const std::size_t num_points = 10000;
//     const data_t min = 0, max = 1000;
//     SetUp::generator =
//         std::make_unique<DataGenerator1D<data_t>>(num_points, min, max);
//   }

//  public:
//   static void PerformSetUp() { static SetUp setUp; }
//   inline static std::unique_ptr<DataGenerator1D<data_t>> generator;
// };

// template <class SpatialDS>
// static void BM_concurrency(benchmark::State& state) {
//   SetUp::PerformSetUp();
//   const data_t max = 1000;

//   SpatialDS instancia;
//   auto points = SetUp::generator->get_data();

//   for (auto& p : points) {
//     instancia.insert(p);
//   }

//   point_t query_min = point_t({max * 0.2});
//   point_t query_max = point_t({max * 0.8});

//   for (auto _ : state) {
//     auto result = instancia.range(query_min, query_max);
//   }
// }

// BENCHMARK_TEMPLATE(BM_concurrency, Validator<point_t>);
// BENCHMARK_TEMPLATE(BM_concurrency, BasicSpatial<point_t>);

BENCHMARK_MAIN();