/**
 * @file vertex_test.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/vertex.h"

#include "../include/main.test.h"
#include "include/model/transform_matrix_builder.h"

namespace s21 {
TEST(VertexTest, PositionInitialization) {
  s21::Point3D initial_position{1.0f, 2.0f, 3.0f};
  s21::Vertex vertex;
  vertex.set_position(initial_position);

  EXPECT_EQ(initial_position.x, 1.0f);
  EXPECT_EQ(initial_position.y, 2.0f);
  EXPECT_EQ(initial_position.z, 3.0f);

  EXPECT_EQ(vertex.position().x, 1.0f);
  EXPECT_EQ(vertex.position().y, 2.0f);
  EXPECT_EQ(vertex.position().z, 3.0f);
}

TEST(VertexTest, Transform) {
  s21::Vertex vertex;
  vertex.set_position({1.0f, 1.0f, 1.0f});

  s21::TransformMatrix matrix =
      s21::TransformMatrixBuilder::CreateMoveMatrix(1.0f, 1.0f, 1.0f);
  vertex.Transform(matrix);

  EXPECT_EQ(vertex.position().x, 2.0f);
  EXPECT_EQ(vertex.position().y, 2.0f);
  EXPECT_EQ(vertex.position().z, 2.0f);
}
}  // namespace s21
