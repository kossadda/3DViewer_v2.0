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

#include "../include/model/transform_matrix.h"

namespace s21 {
TransformMatrix::TransformMatrix() noexcept {
  for (int i = 0; i < kSize; ++i) {
    for (int j = 0; j < kSize; ++j) {
      m_[i][j] = (i == j) ? 1.f : 0.f;
    }
  }
}

TransformMatrix TransformMatrix::operator*(const TransformMatrix &other) const {
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

}  // namespace s21
