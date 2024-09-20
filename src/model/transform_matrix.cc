/**
 * @file transform_matrix.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Implementation of the TransformMatrix class
 * @version 1.0
 * @date 2024-09-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/transform_matrix.h"

namespace s21 {
TransformMatrix::TransformMatrix() noexcept {
  for (int i = 0; i < kSize; ++i) {
    for (int j = 0; j < kSize; ++j) {
      m_[i][j] = (i == j) ? 1.f : 0.f;
    }
  }
}

TransformMatrix TransformMatrix::operator*(
    const TransformMatrix &other) const noexcept {
  TransformMatrix res;

  for (int i = 0; i < kSize; ++i) {
    for (int j = 0; j < kSize; ++j) {
      res.m_[i][j] = 0.f;

      for (int k = 0; k < kSize; ++k) {
        res.m_[i][j] += m_[i][k] * other.m_[k][j];
      }
    }
  }

  return res;
}

Point3D TransformMatrix::TransformPoint(const Point3D &other) const noexcept {
  Point3D res;

  res.x =
      m_[0][0] * other.x + m_[0][1] * other.y + m_[0][2] * other.z + m_[0][3];
  res.y =
      m_[1][0] * other.x + m_[1][1] * other.y + m_[1][2] * other.z + m_[1][3];
  res.z =
      m_[2][0] * other.x + m_[2][1] * other.y + m_[2][2] * other.z + m_[2][3];

  return res;
}

void TransformMatrix::set_element(const int row, const int col,
                                  float value) noexcept {
  m_[row][col] = value;
}

}  // namespace s21
