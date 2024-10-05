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

void Vertex::Transform(const TransformMatrix &matrix) {
  position_ = matrix.TransformPoint(position_);
}

bool Vertex::operator==(const Vertex &other) const noexcept {
  return position_.x == other.position_.x && position_.y == other.position_.y &&
         position_.z == other.position_.z;
}

Vertex::Vertex(const float x, const float y, const float z)
    : position_{x, y, z} {}

}  // namespace s21
