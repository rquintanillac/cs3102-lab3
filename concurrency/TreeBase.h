#pragma once

namespace utec {
namespace concurrency {

template <typename Point> class TreeBase {
public:
  virtual bool insert(const Point &new_point) = 0;
  virtual bool search(const Point &to_search) = 0;
  virtual bool remove(const Point &to_remove) = 0;
  virtual std::size_t getNumKeys() = 0;
  virtual std::size_t getMaxHeight() = 0;
};

} // namespace concurrency
} // namespace utec