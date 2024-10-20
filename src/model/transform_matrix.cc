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

/**
 * @brief Default constructor.
 *
 * Initializes the matrix with default values (usually the identity matrix).
 * The constructor is marked noexcept to guarantee that it doesn't throw any
 * exceptions.
 */
TransformMatrix::TransformMatrix() {
  for (int i = 0; i < kSize; ++i) {
    for (int j = 0; j < kSize; ++j) {
      m_[i][j] = (i == j) ? 1.f : 0.f;
    }
  }
}

/**
 * @brief Matrix multiplication operator.
 *
 * Performs matrix multiplication between the current matrix and another
 * TransformMatrix. The resulting matrix is returned. The operation is marked
 * noexcept to ensure no exceptions are thrown during matrix multiplication.
 *
 * @param other The other TransformMatrix to multiply with.
 * @return A new TransformMatrix that is the result of the multiplication.
 */
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

/**
 * @brief Transforms a 3D point using the matrix.
 *
 * Applies the transformation matrix to a given 3D point (represented by a
 * Point3D object). This can include operations like translation, rotation, or
 * scaling depending on the matrix. The method is marked noexcept to indicate it
 * will not throw exceptions.
 *
 * @param other A constant reference to the Point3D object to be transformed.
 * @return A new Point3D object representing the transformed point.
 */
Point3D TransformMatrix::TransformPoint(const Point3D &other) const {
  Point3D res;

  res.x =
      m_[0][0] * other.x + m_[0][1] * other.y + m_[0][2] * other.z + m_[0][3];
  res.y =
      m_[1][0] * other.x + m_[1][1] * other.y + m_[1][2] * other.z + m_[1][3];
  res.z =
      m_[2][0] * other.x + m_[2][1] * other.y + m_[2][2] * other.z + m_[2][3];

  return res;
}

/**
 * @brief Sets an element in the matrix.
 *
 * Allows setting a specific element in the matrix by providing the row, column,
 * and the value. The operation is marked noexcept to ensure no exceptions are
 * thrown.
 *
 * @param row The row index of the element (0-based).
 * @param col The column index of the element (0-based).
 * @param value The value to set in the specified position.
 */
void TransformMatrix::set_element(const int row, const int col, float value) {
  m_[row][col] = value;
}

float TransformMatrix::element(int row, int col) const { return m_[row][col]; }

}  // namespace s21
