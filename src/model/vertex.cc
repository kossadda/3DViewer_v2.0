/**
 * @file vertex.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Implementation file for the Vertex class
 * @version 1.0
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/vertex.h"

namespace s21 {

/**
 * @brief Constructs a Vertex from a Point3D object.
 *
 * This constructor allows creating a Vertex by passing an instance of Point3D.
 * It is marked as noexcept since it is guaranteed not to throw any exceptions.
 *
 * @param point A constant reference to a Point3D object representing the
 * position.
 */
Vertex::Vertex(const Point3D &point) : position_{point} {}

/**
 * @brief Constructor to initialize a Vertex with x, y, z coordinates.
 *
 * @param x The x-coordinate of the vertex.
 * @param y The y-coordinate of the vertex.
 * @param z The z-coordinate of the vertex.
 */
Vertex::Vertex(float x, float y, float z) : position_{x, y, z} {}

/**
 * @brief Transforms the Vertex using a transformation matrix.
 *
 * Applies the provided TransformMatrix to the current vertex and returns the
 * transformed vertex. The method is marked as noexcept, ensuring no exceptions
 * are thrown.
 *
 * @param matrix A constant reference to the transformation matrix.
 * @return A new Vertex object after applying the transformation.
 */
Vertex Vertex::Transform(const TransformMatrix &matrix) const {
  return Vertex{matrix.TransformPoint(position_)};
}

/**
 * @brief Normalizes the Vertex.
 *
 * Adjusts the vertex's position by a normalization parameter.
 *
 * @param normalize_param The value by which the vertex is normalized.
 * @return A reference to the current Vertex object after normalization.
 */
Vertex &Vertex::Normalize(float normalize_param) {
  position_.x /= normalize_param;
  position_.y /= normalize_param;
  position_.z /= normalize_param;

  return *this;
}

/**
 * @brief Equality operator.
 *
 * Compares two Vertex objects for equality by comparing their positions.
 * This operation is marked noexcept since it will not throw exceptions.
 *
 * @param other The other Vertex object to compare.
 * @return True if the two vertices have the same position, false otherwise.
 */
bool Vertex::operator==(const Vertex &other) const {
  return position_ == other.position_;
}

}  // namespace s21
