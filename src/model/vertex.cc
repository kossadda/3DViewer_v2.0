/**
 * @file vertex.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/vertex.h"

namespace s21 {
void Vertex::Transform(const TransformMatrix &matrix) {
  position_ = matrix.TransformPoint(position_);
}

}  // namespace s21
