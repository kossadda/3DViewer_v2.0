/**
 * @file figure.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_FIGURE_H_
#define SRC_INCLUDE_MODEL_FIGURE_H_

#include <vector>

#include "include/model/edge.h"
#include "include/model/scene_object.h"
#include "include/model/vertex.h"

namespace s21 {
class Figure : SceneObject {
 public:
  Figure(const std::vector<Vertex> &vertices,
         const std::vector<Edge> edges) noexcept;

  inline const std::vector<Vertex> &vertices() const noexcept {
    return vertices_;
  }

  inline const std::vector<Edge> &edges() const noexcept { return edges_; }

  void Transform(const TransformMatrix &matrix) override;

 private:
  std::vector<Vertex> vertices_;
  std::vector<Edge> edges_;
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_FIGURE_H_
