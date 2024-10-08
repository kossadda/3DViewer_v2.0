/**
 * @file scene.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_SCENE_H_
#define SRC_INCLUDE_MODEL_SCENE_H_

#include <vector>

#include "include/model/edge.h"
#include "include/model/vertex.h"

namespace s21 {
class Scene {
 public:
  Scene() = default;
  Scene(const std::vector<Edge>& edges,
        const std::vector<Vertex>& vertices) noexcept;

  inline std::vector<Edge> edges() const noexcept { return edges_; }

  inline std::vector<Vertex> vertices() const noexcept { return vertices_; }
  void Transform(const TransformMatrix& matrix) noexcept;

 private:
  std::vector<Edge> edges_;
  std::vector<Vertex> vertices_;
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_SCENE_H_
