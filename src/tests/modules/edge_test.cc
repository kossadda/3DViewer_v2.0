/**
 * @file edge_test.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/edge.h"

#include "../include/main.test.h"

namespace s21 {
TEST(EdgeTest, InitializationAndAccess) {
  s21::Vertex vertex1{1.0f, 2.0f, 3.0f};
  s21::Vertex vertex2{4.0f, 5.0f, 6.0f};

  s21::Edge edge(vertex1, vertex2);

  EXPECT_EQ(edge.begin().position().x, 1.0f);
  EXPECT_EQ(edge.begin().position().y, 2.0f);
  EXPECT_EQ(edge.begin().position().z, 3.0f);

  EXPECT_EQ(edge.end().position().x, 4.0f);
  EXPECT_EQ(edge.end().position().y, 5.0f);
  EXPECT_EQ(edge.end().position().z, 6.0f);
}
}  // namespace s21
