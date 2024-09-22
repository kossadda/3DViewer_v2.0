/**
 * @file figure.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/figure.h"

namespace s21 {
Figure::Figure(const std::vector<Vertex> &vertices,
               const std::vector<Edge> edges) noexcept
    : vertices_{vertices}, edges_{edges} {}

void Figure::Transform(const TransformMatrix &matrix) {
  for (auto &vertex : vertices_) {
    vertex.Transform(matrix);
  }
}

}  // namespace s21
