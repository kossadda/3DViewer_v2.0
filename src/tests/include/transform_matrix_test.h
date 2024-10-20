/**
 * @file transform_matrix_test.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_TESTS_INCLUDE_TRANSFORM_MATRIX_TEST_H_
#define SRC_TESTS_INCLUDE_TRANSFORM_MATRIX_TEST_H_

#include <gtest/gtest.h>

#include <cmath>

#include "include/model/transform_matrix.h"
#include "include/model/transform_matrix_builder.h"

namespace s21 {

class TransformMatrixTest : public ::testing::Test {
 public:
  void result_matrix(const TransformMatrix &result) { matrix_ = result; }

  void expected_matrix(const TransformMatrix &expected) {
    exp_matrix_ = expected;
  }

  void result_point(const Point3D &result) { point_ = result; }

  void expected_point(const Point3D &expected) { exp_point_ = expected; }

  TransformMatrix to_matrix(const float massive[4][4]) {
    TransformMatrix matrix;

    for (int i{}; i < 4; ++i) {
      for (int j{}; j < 4; ++j) {
        matrix.set_element(i, j, massive[i][j]);
      }
    }

    return matrix;
  }

  void compare_matrix() {
    for (int i{}; i < 4; ++i) {
      for (int j{}; j < 4; ++j) {
        EXPECT_NEAR(matrix_.element(i, j), exp_matrix_.element(i, j), 1e-6);
      }
    }
  }

  void compare_point() {
    EXPECT_NEAR(point_.x, exp_point_.x, 1e-6);
    EXPECT_NEAR(point_.y, exp_point_.y, 1e-6);
    EXPECT_NEAR(point_.z, exp_point_.z, 1e-6);
  }

 protected:
  void SetUp() override {
    for (int i{}; i < 4; ++i) {
      for (int j{}; j < 4; ++j) {
        if (i == j) {
          exp_matrix_.set_element(i, j, 1.0f);
        } else {
          exp_matrix_.set_element(i, j, 0.0f);
        }
      }
    }
  }

  TransformMatrix matrix_;
  TransformMatrix exp_matrix_;
  Point3D point_;
  Point3D exp_point_;
};

}  // namespace s21

#endif  // SRC_TESTS_INCLUDE_TRANSFORM_MATRIX_TEST_H_
