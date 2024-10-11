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
Scene::Scene(const std::vector<int>& indices,
             const std::vector<Vertex>& vertices) noexcept
    : indices_{indices}, vertices_{vertices}, data_{vertices} {}

void Scene::Transform(const TransformMatrix& matrix) noexcept {
  for (std::size_t i{}; i < data_.size(); ++i) {
    vertices_[i] = data_[i].Transform(matrix);
  }
}

}  // namespace s21
