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
void Scene::TransformFigures(const TransformMatrix& matrix) noexcept {
  for (auto& figure : figures_) {
    figure.Transform(matrix);
  }
}

void Scene::AddFigure(const Figure& figure) noexcept {
  figures_.push_back(figure);
}
}  // namespace s21
