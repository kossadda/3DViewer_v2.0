/**
 * @file 3d_point_test.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../../include/model/3d_point.h"

#include "../include/main.test.h"

namespace s21 {

TEST(Point3DTest, InitializationTest) {
  Point3D point(1.0f, 2.0f, 3.0f);
  EXPECT_FLOAT_EQ(point.x, 1.0f);
  EXPECT_FLOAT_EQ(point.y, 2.0f);
  EXPECT_FLOAT_EQ(point.z, 3.0f);
}

TEST(Point3DTest, InitializationWithNegativeValues) {
  Point3D point(-1.0f, -2.0f, -3.0f);
  EXPECT_FLOAT_EQ(point.x, -1.0f);
  EXPECT_FLOAT_EQ(point.y, -2.0f);
  EXPECT_FLOAT_EQ(point.z, -3.0f);
}

TEST(Point3DTest, InitializationWithZero) {
  Point3D point(0.0f, 0.0f, 0.0f);
  EXPECT_FLOAT_EQ(point.x, 0.0f);
  EXPECT_FLOAT_EQ(point.y, 0.0f);
  EXPECT_FLOAT_EQ(point.z, 0.0f);
}

TEST(Point3DTest, InitializationDefault) {
  Point3D point;
  EXPECT_FLOAT_EQ(point.x, 0.0f);
  EXPECT_FLOAT_EQ(point.y, 0.0f);
  EXPECT_FLOAT_EQ(point.z, 0.0f);
}
}  // namespace s21
