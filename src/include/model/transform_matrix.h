/**
 * @file transform_matrix.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Header file for the TransformMatrix class
 * @version 1.0
 * @date 2024-09-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_TRANSFORM_MATRIX_H_
#define SRC_INCLUDE_MODEL_TRANSFORM_MATRIX_H_

#include "include/model/3d_point.h"

namespace s21 {
class TransformMatrix {
 public:
  TransformMatrix() noexcept;
  TransformMatrix operator*(const TransformMatrix &other) const noexcept;
  Point3D TransformPoint(const Point3D &other) const noexcept;

 private:
  static constexpr int kSize = 4;

  float m_[kSize][kSize];
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_TRANSFORM_MATRIX_H_
