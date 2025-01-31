/**
 * @file transform_matrix_builder.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Implementation file for the TransformMatrixBuilder class
 * @version 1.0
 * @date 2024-09-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/transform_matrix_builder.h"

#include <cmath>

namespace s21 {

/**
 * @brief Creates a rotation matrix.
 *
 * Generates a 4x4 rotation matrix based on the provided rotation angles
 * (in radians) around the x, y, and z axes.
 * This matrix can be used to apply a rotation transformation to a 3D object.
 * The method is marked noexcept to ensure that no exceptions are thrown.
 *
 * @param x Rotation angle around the x-axis, in radians.
 * @param y Rotation angle around the y-axis, in radians.
 * @param z Rotation angle around the z-axis, in radians.
 * @return A TransformMatrix representing the rotation.
 */
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

/**
 * @brief Creates a translation (move) matrix.
 *
 * Generates a 4x4 translation matrix that moves a 3D object by the specified
 * amounts along the x, y, and z axes. The method is marked noexcept to ensure
 * that no exceptions are thrown.
 *
 * @param x The amount to move along the x-axis.
 * @param y The amount to move along the y-axis.
 * @param z The amount to move along the z-axis.
 * @return A TransformMatrix representing the translation.
 */
TransformMatrix TransformMatrixBuilder::CreateMoveMatrix(float x, float y,
                                                         float z) noexcept {
  TransformMatrix res;

  res.set_element(0, 3, x);
  res.set_element(1, 3, y);
  res.set_element(2, 3, z);

  return res;
}

/**
 * @brief Creates a scaling matrix.
 *
 * Generates a 4x4 scaling matrix that scales a 3D object by the specified
 * factors along the x, y, and z axes. The method is marked noexcept to ensure
 * that no exceptions are thrown.
 *
 * @param x The scaling factor along the x-axis.
 * @param y The scaling factor along the y-axis.
 * @param z The scaling factor along the z-axis.
 * @return A TransformMatrix representing the scaling transformation.
 */
TransformMatrix TransformMatrixBuilder::CreateScaleMatrix(float x, float y,
                                                          float z) noexcept {
  TransformMatrix matrix;

  matrix.set_element(0, 0, x);
  matrix.set_element(1, 1, y);
  matrix.set_element(2, 2, z);

  return matrix;
}

}  // namespace s21
