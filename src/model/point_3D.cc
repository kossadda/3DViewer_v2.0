/**
 * @file point_3D.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Implementation of a class representing a point in 3D space
 * @version 1.0
 * @date 2024-09-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/point_3D.h"

namespace s21 {
/**
 * @brief Parameterized constructor.
 *
 * Initializes a `Point3D` object with the specified `x`, `y`, and `z`
 * coordinates.
 *
 * @param x A floating-point value representing the x-coordinate.
 * @param y A floating-point value representing the y-coordinate.
 * @param z A floating-point value representing the z-coordinate.
 */
Point3D::Point3D(float x, float y, float z) : x{x}, y{y}, z{z} {}

/**
 * @brief Equality comparison operator.
 *
 * Compares two `Point3D` objects for equality. Two points are considered equal
 * if their `x`, `y`, and `z` coordinates are the same.
 *
 * @param other A constant reference to another `Point3D` object.
 * @return True if the points are equal, otherwise false.
 */
bool Point3D::operator==(const Point3D& other) const noexcept {
  return x == other.x && y == other.y && z == other.z;
}

}  // namespace s21
