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

#include "include/model/figure.h"

namespace s21 {
class Scene {
 public:
  Scene() = default;

  inline const std::vector<Figure>& figures() const noexcept {
    return figures_;
  }

  void TransformFigures(const TransformMatrix& matrix) noexcept;
  void AddFigure(const Figure& figure) noexcept;

 private:
  std::vector<Figure> figures_;
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_SCENE_H_
