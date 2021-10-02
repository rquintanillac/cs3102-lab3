#pragma once

#include "TreeBase.h"

namespace utec {
namespace concurrency {

/**
 * AVLThreadSafe implementation
 */
template <typename Point> class AVLThreadSafe : public TreeBase<Point> {
private:
public:
  AVLThreadSafe(){};

  bool insert(const Point &new_point) override {}
  bool search(const Point &to_search) override {}
  bool remove(const Point &to_remove) override {}
  std::size_t getNumKeys() override { return 0; }
  std::size_t getMaxHeight() override { return 0; }
};

} // namespace concurrency
} // namespace utec
