/**
 * @file vertex.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Header file for the Vertex class representing a vertex in 3D space
 * @version 1.0
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_VERTEX_H_
#define SRC_INCLUDE_MODEL_VERTEX_H_

#include "include/model/point_3D.h"
#include "include/model/transform_matrix.h"

namespace s21 {

/**
 * @class Vertex
 * @brief Represents a 3D vertex in space.
 *
 * The Vertex class encapsulates a point in 3D space using a Point3D object
 * and provides functionality for transforming and normalizing vertices.
 */
class Vertex {
 public:
  Vertex() = default;
  Vertex(float x, float y, float z);
  explicit Vertex(const Point3D &point) noexcept;

  inline const Point3D &position() const noexcept { return position_; }
  inline void set_position(const Point3D &point) noexcept { position_ = point; }

  Vertex Transform(const TransformMatrix &matrix) const noexcept;
  Vertex &Normalize(float normalize_param);

  bool operator==(const Vertex &other) const noexcept;

 private:
  Point3D position_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_VERTEX_H_
