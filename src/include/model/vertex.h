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

#include "include/model/3d_point.h"
#include "include/model/scene_object.h"

namespace s21 {
class Vertex : public SceneObject {
 public:
  Vertex() = default;
  explicit Vertex(const Point3D &point) noexcept;
  inline Point3D position() const noexcept { return position_; }
  inline void set_position(const Point3D &point) noexcept { position_ = point; }
  void Transform(const TransformMatrix &matrix) override;

 private:
  Point3D position_;
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_VERTEX_H_
