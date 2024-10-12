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

Vertex Vertex::Transform(const TransformMatrix &matrix) const noexcept {
  return Vertex{matrix.TransformPoint(position_)};
}

Vertex &Vertex::Normalize(float normalize_param) {
  position_.x /= normalize_param;
  position_.y /= normalize_param;
  position_.z /= normalize_param;

  return *this;
}

bool Vertex::operator==(const Vertex &other) const noexcept {
  return position_ == other.position_;
}

}  // namespace s21
