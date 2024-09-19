/**
 * @file transform_matrix_builder.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/transform_matrix_builder.h"

namespace s21 {
TransformMatrix TransformMatrixBuilder::CreateRotationMatrix(float x, float y,
                                                             float z) noexcept {
}

TransformMatrix TransformMatrixBuilder::CreateMoveMatrix(float x, float y,
                                                         float z) noexcept {}

TransformMatrix TransformMatrixBuilder::CreateScaleMatrix(float x, float y,
                                                          float z) noexcept {
  TransformMatrix matrix;

  matrix.m_[0][0] = x;
  matrix.m_[1][1] = y;
  matrix.m_[2][2] = z;

  return matrix;
}
}  // namespace s21
