/**
 * @file scene.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/scene.h"

namespace s21 {
Scene::Scene(const std::vector<Edge>& edges,
             const std::vector<Vertex>& vertices) noexcept
    : edges_{edges}, vertices_{vertices} {}

void Scene::Transform(const TransformMatrix& matrix) noexcept {
  for (auto& vertex : vertices_) {
    vertex.Transform(matrix);
  }
}

}  // namespace s21
