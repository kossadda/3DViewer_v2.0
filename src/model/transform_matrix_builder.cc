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

#include <cmath>

namespace s21 {
TransformMatrix TransformMatrixBuilder::CreateRotationMatrix(float x, float y,
                                                             float z) noexcept {
  TransformMatrix rot_x, rot_y, rot_z;

  x *= kRadian;
  y *= kRadian;
  z *= kRadian;

  rot_x.set_element(1, 1, cos(x));
  rot_x.set_element(1, 2, -sin(x));
  rot_x.set_element(2, 1, sin(x));
  rot_x.set_element(2, 2, cos(x));

  rot_y.set_element(0, 0, cos(y));
  rot_y.set_element(0, 2, sin(y));
  rot_y.set_element(2, 0, -sin(y));
  rot_y.set_element(2, 2, cos(y));

  rot_z.set_element(0, 0, cos(z));
  rot_z.set_element(0, 1, -sin(z));
  rot_z.set_element(1, 0, sin(z));
  rot_z.set_element(1, 1, cos(z));

  return rot_x * rot_y * rot_z;
}

TransformMatrix TransformMatrixBuilder::CreateMoveMatrix(float x, float y,
                                                         float z) noexcept {
  TransformMatrix res;

  x /= 50.f;
  y /= 50.f;
  z /= 50.f;

  res.set_element(0, 3, x);
  res.set_element(1, 3, y);
  res.set_element(2, 3, z);

  return res;
}

TransformMatrix TransformMatrixBuilder::CreateScaleMatrix(float x, float y,
                                                          float z) noexcept {
  TransformMatrix matrix;

  matrix.set_element(0, 0, x);
  matrix.set_element(1, 1, y);
  matrix.set_element(2, 2, z);

  return matrix;
}

const float TransformMatrixBuilder::kRadian = 0.0174533;
}  // namespace s21
