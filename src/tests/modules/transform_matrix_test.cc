/**
 * @file transform_matrix_test.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include/transform_matrix_test.h"

namespace s21 {

TEST_F(TransformMatrixTest, constructor) { compare_matrix(); }

TEST_F(TransformMatrixTest, multiplyWithIdentityMatrix) {
  float matrix[4][4] = {{1.0f, 2.0f, 3.0f, 4.0f},
                        {5.f, 6.f, 7.f, 8.f},
                        {9.f, 10.f, 11.f, 12.f},
                        {13.f, 14.f, 15.f, 16.f}};

  expected_matrix(to_matrix(matrix));
  result_matrix(to_matrix(matrix) * TransformMatrix{});

  compare_matrix();
}

TEST_F(TransformMatrixTest, multiplyTwoMatrices) {
  float first[4][4] = {{1.0f, 2.0f, 3.0f, 4.0f},
                       {5.0f, 6.0f, 7.0f, 8.0f},
                       {9.0f, 10.0f, 11.0f, 12.0f},
                       {13.0f, 14.0f, 15.0f, 16.0f}};
  float second[4][4] = {{1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 1.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 1.0f, 0.0f},
                        {0.0f, 0.0f, 0.0f, 1.0f}};

  expected_matrix(to_matrix(first));
  result_matrix(to_matrix(first) * to_matrix(second));

  compare_matrix();
}

TEST_F(TransformMatrixTest, multiplyWithZeroMatrix) {
  float first[4][4] = {{1.0f, 2.0f, 3.0f, 4.0f},
                       {5.0f, 6.0f, 7.0f, 8.0f},
                       {9.0f, 10.0f, 11.0f, 12.0f},
                       {13.0f, 14.0f, 15.0f, 16.0f}};
  float second[4][4] = {{0.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 0.0f, 0.0f}};

  expected_matrix(to_matrix(second));
  result_matrix(to_matrix(first) * to_matrix(second));

  compare_matrix();
}

TEST_F(TransformMatrixTest, multiplyWithDiagonalMatrix) {
  float first[4][4] = {{2.0f, 0.0f, 0.0f, 0.0f},
                       {0.0f, 3.0f, 0.0f, 0.0f},
                       {0.0f, 0.0f, 4.0f, 0.0f},
                       {0.0f, 0.0f, 0.0f, 5.0f}};
  float second[4][4] = {{1.0f, 2.0f, 3.0f, 4.0f},
                        {5.0f, 6.0f, 7.0f, 8.0f},
                        {9.0f, 10.0f, 11.0f, 12.0f},
                        {13.0f, 14.0f, 15.0f, 16.0f}};
  float exp[4][4] = {{2.0f, 4.0f, 6.0f, 8.0f},
                     {15.0f, 18.0f, 21.0f, 24.0f},
                     {36.0f, 40.0f, 44.0f, 48.0f},
                     {65.0f, 70.0f, 75.0f, 80.0f}};

  expected_matrix(to_matrix(exp));
  result_matrix(to_matrix(first) * to_matrix(second));

  compare_matrix();
}

TEST_F(TransformMatrixTest, multiplySymmetricMatrices) {
  float first[4][4] = {{2.0f, 0.0f, 0.0f, 0.0f},
                       {0.0f, 3.0f, 0.0f, 0.0f},
                       {0.0f, 0.0f, 4.0f, 0.0f},
                       {0.0f, 0.0f, 0.0f, 5.0f}};
  float second[4][4] = {{1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 2.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 3.0f, 0.0f},
                        {0.0f, 0.0f, 0.0f, 4.0f}};
  float exp[4][4] = {{2.0f, 0.0f, 0.0f, 0.0f},
                     {0.0f, 6.0f, 0.0f, 0.0f},
                     {0.0f, 0.0f, 12.0f, 0.0f},
                     {0.0f, 0.0f, 0.0f, 20.0f}};

  expected_matrix(to_matrix(exp));
  result_matrix(to_matrix(first) * to_matrix(second));

  compare_matrix();
}

TEST_F(TransformMatrixTest, multiplyWithNegativeValues) {
  float first[4][4] = {{-1.0f, 2.0f, -3.0f, 4.0f},
                       {-5.0f, 6.0f, -7.0f, 8.0f},
                       {-9.0f, 10.0f, -11.0f, 12.0f},
                       {-13.0f, 14.0f, -15.0f, 16.0f}};
  float second[4][4] = {{-1.0f, -2.0f, -3.0f, -4.0f},
                        {-5.0f, -6.0f, -7.0f, -8.0f},
                        {-9.0f, -10.0f, -11.0f, -12.0f},
                        {-13.0f, -14.0f, -15.0f, -16.0f}};
  float exp[4][4] = {{-34.0f, -36.0f, -38.0f, -40.0f},
                     {-66.0f, -68.0f, -70.0f, -72.0f},
                     {-98.0f, -100.0f, -102.0f, -104.0f},
                     {-130.0f, -132.0f, -134.0f, -136.0f}};

  expected_matrix(to_matrix(exp));
  result_matrix(to_matrix(first) * to_matrix(second));

  compare_matrix();
}

TEST_F(TransformMatrixTest, transformPoint) {
  float matrix[4][4] = {{1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 1.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 1.0f, 0.0f},
                        {0.0f, 0.0f, 0.0f, 1.0f}};

  expected_point({1.0f, 2.0f, 3.0f});
  result_point(to_matrix(matrix).TransformPoint({1.0f, 2.0f, 3.0f}));

  compare_point();
}

TEST_F(TransformMatrixTest, transformPointRandom_1) {
  float matrix[4][4] = {{2.0f, 3.0f, 4.0f, 0.0f},
                        {5.0f, 6.0f, 1.0f, 0.0f},
                        {2.0f, 3.0f, 1.0f, 0.0f},
                        {0.0f, 0.0f, 0.0f, 1.0f}};

  expected_point({68.0f, 113.0f, 56.0f});
  result_point(to_matrix(matrix).TransformPoint({5.0f, 14.0f, 4.0f}));

  compare_point();
}

TEST_F(TransformMatrixTest, MoveMatrixTest) {
  float exp[4][4] = {{1.0f, 0.0f, 0.0f, 1.0f},
                     {0.0f, 1.0f, 0.0f, 2.0f},
                     {0.0f, 0.0f, 1.0f, 3.0f},
                     {0.0f, 0.0f, 0.0f, 1.0f}};

  expected_matrix(to_matrix(exp));
  result_matrix(TransformMatrixBuilder::CreateMoveMatrix(1.0f, 2.0f, 3.0f));

  compare_matrix();
}

TEST_F(TransformMatrixTest, ScaleMatrixTest) {
  float exp[4][4] = {{2.0f, 0.0f, 0.0f, 0.0f},
                     {0.0f, 3.0f, 0.0f, 0.0f},
                     {0.0f, 0.0f, 4.0f, 0.0f},
                     {0.0f, 0.0f, 0.0f, 1.0f}};

  expected_matrix(to_matrix(exp));
  result_matrix(TransformMatrixBuilder::CreateScaleMatrix(2.0f, 3.0f, 4.0f));

  compare_matrix();
}

TEST_F(TransformMatrixTest, RotationMatrixTest) {
  float exp[4][4] = {{0.999624193f, -0.0274121445f, 0.0f, 0.0f},
                     {0.0274121445f, 0.999624193f, 0.0f, 0.0f},
                     {0.0f, 0.0f, 1.0f, 0.0f},
                     {0.0f, 0.0f, 0.0f, 1.0f}};

  expected_matrix(to_matrix(exp));
  result_matrix(
      TransformMatrixBuilder::CreateRotationMatrix(0.0f, 0.0f, M_PI_2));

  compare_matrix();
}

}  // namespace s21
