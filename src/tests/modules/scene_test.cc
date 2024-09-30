/**
 * @file scene_test.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/scene.h"

#include "../include/main.test.h"

namespace s21 {
TEST(SceneTest, AddFigureTest) {
  Scene scene;
  Vertex v1{0, 0, 0};
  Vertex v2{1, 1, 1};
  Figure figure({v1, v2}, {Edge(v1, v2)});
  scene.AddFigure(figure);

  EXPECT_EQ(scene.figures().size(), 1);
}

TEST(SceneTest, TransformFiguresTest) {
  s21::Scene scene;
  s21::Vertex v1{0, 0, 0};
  s21::Vertex v2{1, 1, 1};
  s21::Figure figure({v1, v2}, {s21::Edge(v1, v2)});
  scene.AddFigure(figure);

  s21::TransformMatrix matrix;
  scene.TransformFigures(matrix);

  EXPECT_EQ(scene.figures().size(), 1);
}
}  // namespace s21
