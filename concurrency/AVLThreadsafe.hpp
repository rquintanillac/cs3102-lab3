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

  /**
   * Obtiene el número de claves en el árbol. El árbol
   * entero debe ser recorrido recursivamente para contar
   * las claves.
   *
   * @return número de claves, 0 si el árbol está vacío.
   */
  std::size_t getNumKeys() override { return 0; }

  /**
   * Obtiene la altura máxima del árbol. Se debe reportar
   * el mayor valor de todos los subárboles de manera
   * recursiva.
   *
   * @return número de claves, 0 si el árbol está vacío.
   */
  std::size_t getMaxHeight() override { return 0; }

  bool isBalanced() {
    std::size_t max_height = getMaxHeight();

    if (max_height <= 1)
      return true;
    return false;
  }
};

} // namespace concurrency
} // namespace utec
