/**
 * @file 3d_point.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Implementation of a class representing a point in 3D space
 * @version 1.0
 * @date 2024-09-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/3d_point.h"

namespace s21 {
Point3D::Point3D(float x, float y, float z) : x{x}, y{y}, z{z} {}

bool Point3D::operator==(const Point3D& other) const noexcept {
  return x == other.x && y == other.y && z == other.z;
}

}  // namespace s21
