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

#include "include/model/point_3D.h"

namespace s21 {

/**
 * @class TransformMatrix
 * @brief A class for representing and manipulating 4x4 transformation matrices.
 *
 * The TransformMatrix class provides functionality for working with 4x4
 * matrices commonly used in 3D transformations, such as translation, rotation,
 * and scaling. It includes matrix multiplication and point transformation
 * methods.
 */
class TransformMatrix {
 public:
  TransformMatrix();

  void set_element(int row, int col, float value);
  float element(int row, int col) const;

  TransformMatrix operator*(const TransformMatrix &other) const;
  Point3D TransformPoint(const Point3D &other) const;

 private:
  static constexpr int kSize = 4;
  float m_[kSize][kSize];
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_TRANSFORM_MATRIX_H_
