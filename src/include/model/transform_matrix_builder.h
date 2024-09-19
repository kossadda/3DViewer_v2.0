/**
 * @file transform_matrix_builder.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_TRANSFORM_MATRIX_BUILDER_H_
#define SRC_INCLUDE_MODEL_TRANSFORM_MATRIX_BUILDER_H_

#include "include/model/transform_matrix.h"

namespace s21 {
class TransformMatrixBuilder {
  static TransformMatrix CreateRotationMatrix(float x, float y,
                                              float z) noexcept;
  static TransformMatrix CreateMoveMatrix(float x, float y, float z) noexcept;
  static TransformMatrix CreateScaleMatrix(float x, float y, float z) noexcept;
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_TRANSFORM_MATRIX_BUILDER_H_
