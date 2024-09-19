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
#define private public
#define protected public
#include "../../include/model/transform_matrix.h"
#undef private
#undef protected

#include "../include/main.test.h"

namespace s21 {
TEST(TransformMatrixTest, Constructor) {
  TransformMatrix matrix;
  for (int i = 0; i < TransformMatrix::kSize; ++i) {
    for (int j = 0; j < TransformMatrix::kSize; ++j) {
      if (i == j) {
        EXPECT_FLOAT_EQ(matrix.m_[i][j], 1.f);
      } else {
        EXPECT_FLOAT_EQ(matrix.m_[i][j], 0.f);
      }
    }
  }
}

TEST(TransformMatrixTest, MultiplyWithIdentityMatrix) {
  TransformMatrix identity_matrix;
  TransformMatrix matrix;

  matrix.m_[0][0] = 1.0f;
  matrix.m_[0][1] = 2.0f;
  matrix.m_[0][2] = 3.0f;
  matrix.m_[0][3] = 4.0f;
  matrix.m_[1][0] = 5.0f;
  matrix.m_[1][1] = 6.0f;
  matrix.m_[1][2] = 7.0f;
  matrix.m_[1][3] = 8.0f;
  matrix.m_[2][0] = 9.0f;
  matrix.m_[2][1] = 10.0f;
  matrix.m_[2][2] = 11.0f;
  matrix.m_[2][3] = 12.0f;
  matrix.m_[3][0] = 13.0f;
  matrix.m_[3][1] = 14.0f;
  matrix.m_[3][2] = 15.0f;
  matrix.m_[3][3] = 16.0f;

  TransformMatrix result = matrix * identity_matrix;

  for (int i = 0; i < TransformMatrix::kSize; ++i) {
    for (int j = 0; j < TransformMatrix::kSize; ++j) {
      EXPECT_FLOAT_EQ(matrix.m_[i][j], result.m_[i][j]);
    }
  }
}

TEST(TransformMatrixTest, MultiplyTwoMatrices) {
  TransformMatrix matrix1;
  TransformMatrix matrix2;

  matrix1.m_[0][0] = 1.0f;
  matrix1.m_[0][1] = 2.0f;
  matrix1.m_[0][2] = 3.0f;
  matrix1.m_[0][3] = 4.0f;
  matrix1.m_[1][0] = 5.0f;
  matrix1.m_[1][1] = 6.0f;
  matrix1.m_[1][2] = 7.0f;
  matrix1.m_[1][3] = 8.0f;
  matrix1.m_[2][0] = 9.0f;
  matrix1.m_[2][1] = 10.0f;
  matrix1.m_[2][2] = 11.0f;
  matrix1.m_[2][3] = 12.0f;
  matrix1.m_[3][0] = 13.0f;
  matrix1.m_[3][1] = 14.0f;
  matrix1.m_[3][2] = 15.0f;
  matrix1.m_[3][3] = 16.0f;

  matrix2.m_[0][0] = 1.0f;
  matrix2.m_[0][1] = 0.0f;
  matrix2.m_[0][2] = 0.0f;
  matrix2.m_[0][3] = 0.0f;
  matrix2.m_[1][0] = 0.0f;
  matrix2.m_[1][1] = 1.0f;
  matrix2.m_[1][2] = 0.0f;
  matrix2.m_[1][3] = 0.0f;
  matrix2.m_[2][0] = 0.0f;
  matrix2.m_[2][1] = 0.0f;
  matrix2.m_[2][2] = 1.0f;
  matrix2.m_[2][3] = 0.0f;
  matrix2.m_[3][0] = 0.0f;
  matrix2.m_[3][1] = 0.0f;
  matrix2.m_[3][2] = 0.0f;
  matrix2.m_[3][3] = 1.0f;

  TransformMatrix result = matrix1 * matrix2;
  std::vector<std::vector<float>> expected = {{1.0f, 2.0f, 3.0f, 4.0f},
                                              {5.0f, 6.0f, 7.0f, 8.0f},
                                              {9.0f, 10.0f, 11.0f, 12.0f},
                                              {13.0f, 14.0f, 15.0f, 16.0f}};

  for (int i = 0; i < TransformMatrix::kSize; ++i) {
    for (int j = 0; j < TransformMatrix::kSize; ++j) {
      EXPECT_FLOAT_EQ(result.m_[i][j], expected[i][j]);
    }
  }
}

TEST(TransformMatrixTest, MultiplyWithZeroMatrix) {
  TransformMatrix zero_matrix;
  TransformMatrix matrix;

  for (int i = 0; i < TransformMatrix::kSize; ++i) {
    for (int j = 0; j < TransformMatrix::kSize; ++j) {
      zero_matrix.m_[i][j] = 0.0f;
    }
  }

  matrix.m_[0][0] = 1.0f;
  matrix.m_[0][1] = 2.0f;
  matrix.m_[0][2] = 3.0f;
  matrix.m_[0][3] = 4.0f;
  matrix.m_[1][0] = 5.0f;
  matrix.m_[1][1] = 6.0f;
  matrix.m_[1][2] = 7.0f;
  matrix.m_[1][3] = 8.0f;
  matrix.m_[2][0] = 9.0f;
  matrix.m_[2][1] = 10.0f;
  matrix.m_[2][2] = 11.0f;
  matrix.m_[2][3] = 12.0f;
  matrix.m_[3][0] = 13.0f;
  matrix.m_[3][1] = 14.0f;
  matrix.m_[3][2] = 15.0f;
  matrix.m_[3][3] = 16.0f;

  TransformMatrix result = matrix * zero_matrix;

  for (int i = 0; i < TransformMatrix::kSize; ++i) {
    for (int j = 0; j < TransformMatrix::kSize; ++j) {
      EXPECT_FLOAT_EQ(result.m_[i][j], 0.0f);
    }
  }
}

TEST(TransformMatrixTest, MultiplyWithDiagonalMatrix) {
  TransformMatrix matrix1;
  TransformMatrix matrix2;

  matrix1.m_[0][0] = 2.0f;
  matrix1.m_[1][1] = 3.0f;
  matrix1.m_[2][2] = 4.0f;
  matrix1.m_[3][3] = 5.0f;

  matrix2.m_[0][0] = 1.0f;
  matrix2.m_[0][1] = 2.0f;
  matrix2.m_[0][2] = 3.0f;
  matrix2.m_[0][3] = 4.0f;
  matrix2.m_[1][0] = 5.0f;
  matrix2.m_[1][1] = 6.0f;
  matrix2.m_[1][2] = 7.0f;
  matrix2.m_[1][3] = 8.0f;
  matrix2.m_[2][0] = 9.0f;
  matrix2.m_[2][1] = 10.0f;
  matrix2.m_[2][2] = 11.0f;
  matrix2.m_[2][3] = 12.0f;
  matrix2.m_[3][0] = 13.0f;
  matrix2.m_[3][1] = 14.0f;
  matrix2.m_[3][2] = 15.0f;
  matrix2.m_[3][3] = 16.0f;

  std::vector<std::vector<float>> expected = {{2.0f, 4.0f, 6.0f, 8.0f},
                                              {15.0f, 18.0f, 21.0f, 24.0f},
                                              {36.0f, 40.0f, 44.0f, 48.0f},
                                              {65.0f, 70.0f, 75.0f, 80.0f}};

  TransformMatrix result = matrix1 * matrix2;

  for (int i = 0; i < TransformMatrix::kSize; ++i) {
    for (int j = 0; j < TransformMatrix::kSize; ++j) {
      EXPECT_FLOAT_EQ(result.m_[i][j], expected[i][j]);
    }
  }
}

TEST(TransformMatrixTest, MultiplySymmetricMatrices) {
  TransformMatrix matrix1;
  TransformMatrix matrix2;

  matrix1.m_[0][0] = 2.0f;
  matrix1.m_[1][1] = 3.0f;
  matrix1.m_[2][2] = 4.0f;
  matrix1.m_[3][3] = 5.0f;
  matrix2.m_[0][0] = 1.0f;
  matrix2.m_[1][1] = 2.0f;
  matrix2.m_[2][2] = 3.0f;
  matrix2.m_[3][3] = 4.0f;

  std::vector<std::vector<float>> expected = {{2.0f, 0.0f, 0.0f, 0.0f},
                                              {0.0f, 6.0f, 0.0f, 0.0f},
                                              {0.0f, 0.0f, 12.0f, 0.0f},
                                              {0.0f, 0.0f, 0.0f, 20.0f}};

  TransformMatrix result = matrix1 * matrix2;

  for (int i = 0; i < TransformMatrix::kSize; ++i) {
    for (int j = 0; j < TransformMatrix::kSize; ++j) {
      EXPECT_FLOAT_EQ(result.m_[i][j], expected[i][j]);
    }
  }
}

TEST(TransformMatrixTest, MultiplyWithNegativeValues) {
  TransformMatrix matrix1;
  TransformMatrix matrix2;

  matrix1.m_[0][0] = -1.0f;
  matrix1.m_[0][1] = 2.0f;
  matrix1.m_[0][2] = -3.0f;
  matrix1.m_[0][3] = 4.0f;
  matrix1.m_[1][0] = -5.0f;
  matrix1.m_[1][1] = 6.0f;
  matrix1.m_[1][2] = -7.0f;
  matrix1.m_[1][3] = 8.0f;
  matrix1.m_[2][0] = -9.0f;
  matrix1.m_[2][1] = 10.0f;
  matrix1.m_[2][2] = -11.0f;
  matrix1.m_[2][3] = 12.0f;
  matrix1.m_[3][0] = -13.0f;
  matrix1.m_[3][1] = 14.0f;
  matrix1.m_[3][2] = -15.0f;
  matrix1.m_[3][3] = 16.0f;

  matrix2.m_[0][0] = -1.0f;
  matrix2.m_[0][1] = -2.0f;
  matrix2.m_[0][2] = -3.0f;
  matrix2.m_[0][3] = -4.0f;
  matrix2.m_[1][0] = -5.0f;
  matrix2.m_[1][1] = -6.0f;
  matrix2.m_[1][2] = -7.0f;
  matrix2.m_[1][3] = -8.0f;
  matrix2.m_[2][0] = -9.0f;
  matrix2.m_[2][1] = -10.0f;
  matrix2.m_[2][2] = -11.0f;
  matrix2.m_[2][3] = -12.0f;
  matrix2.m_[3][0] = -13.0f;
  matrix2.m_[3][1] = -14.0f;
  matrix2.m_[3][2] = -15.0f;
  matrix2.m_[3][3] = -16.0f;

  std::vector<std::vector<float>> expected = {
      {-34.0f, -36.0f, -38.0f, -40.0f},
      {-66.0f, -68.0f, -70.0f, -72.0f},
      {-98.0f, -100.0f, -102.0f, -104.0f},
      {-130.0f, -132.0f, -134.0f, -136.0f}};

  TransformMatrix result = matrix1 * matrix2;

  for (int i = 0; i < TransformMatrix::kSize; ++i) {
    for (int j = 0; j < TransformMatrix::kSize; ++j) {
      EXPECT_FLOAT_EQ(result.m_[i][j], expected[i][j]);
    }
  }
}

TEST(TransformMatrixTest, TransformPoint) {
  TransformMatrix matrix;

  matrix.m_[0][0] = 1.0;
  matrix.m_[1][1] = 1.0;
  matrix.m_[2][2] = 1.0;
  matrix.m_[3][3] = 1.0;

  Point3D point(1.0, 2.0, 3.0);

  Point3D result = matrix.TransformPoint(point);

  EXPECT_EQ(result.x, 1.0);
  EXPECT_EQ(result.y, 2.0);
  EXPECT_EQ(result.z, 3.0);
}

TEST(TransformMatrixTest, TransformPointRandom1) {
  TransformMatrix matrix;

  matrix.m_[0][0] = 2.0f;
  matrix.m_[0][1] = 3.0f;
  matrix.m_[0][2] = 4.0f;
  matrix.m_[0][3] = 0.0f;
  matrix.m_[1][0] = 5.0f;
  matrix.m_[1][1] = 6.0f;
  matrix.m_[1][2] = 1.0f;
  matrix.m_[1][3] = 0.0f;
  matrix.m_[2][0] = 2.0f;
  matrix.m_[2][1] = 3.0f;
  matrix.m_[2][2] = 1.0f;
  matrix.m_[2][3] = 0.0f;
  matrix.m_[3][0] = 0.0f;
  matrix.m_[3][1] = 0.0f;
  matrix.m_[3][2] = 0.0f;
  matrix.m_[3][3] = 1.0f;

  Point3D point(5.0, 14.0, 4.0);

  Point3D result = matrix.TransformPoint(point);

  EXPECT_EQ(result.x, 68.0);
  EXPECT_EQ(result.y, 113.0);
  EXPECT_EQ(result.z, 56.0);
}
}  // namespace s21
