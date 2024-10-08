/**
 * @file vertex.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/vertex.h"

namespace s21 {
Vertex::Vertex(const Point3D &point) noexcept : position_{point} {}

Vertex::Vertex(float x, float y, float z) : position_{x, y, z} {}

void Vertex::Transform(const TransformMatrix &matrix) {
  position_ = matrix.TransformPoint(position_);
}

bool Vertex::operator==(const Vertex &other) const noexcept {
  return position_ == other.position_;
}

}  // namespace s21
