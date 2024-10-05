/**
 * @file figure_test.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/figure.h"

#include "../include/main.test.h"
#include "include/model/transform_matrix_builder.h"

namespace s21 {

TEST(FigureTest, Constructor) {
  Vertex v_1{1.f, 2.f, 3.f};
  Vertex v_2{4.f, 5.f, 6.f};

  Edge edge(v_1, v_2);

  EXPECT_EQ(edge.begin(), v_1);
  EXPECT_EQ(edge.end(), v_2);

  std::vector<Vertex> v{v_1, v_2};
  std::vector<Edge> e{edge};

  Figure f{v, e};

  EXPECT_EQ(f.vertices().size(), 2);
  EXPECT_EQ(f.edges().size(), 1);
}

TEST(FigureTest, TransformTest) {
  Vertex v_1{1.f, 2.f, 3.f};
  Vertex v_2{4.f, 5.f, 6.f};

  Edge edge(v_1, v_2);
  std::vector<Vertex> vertices{v_1, v_2};
  std::vector<Edge> edges{edge};

  Figure figure(vertices, edges);

  TransformMatrixBuilder matrix;

  figure.Transform(matrix.CreateScaleMatrix(2.0f, 2.0f, 2.0f));

  const std::vector<Vertex>& result_vertices = figure.vertices();
  EXPECT_FLOAT_EQ(result_vertices[0].position().x, 2.f);
  EXPECT_FLOAT_EQ(result_vertices[0].position().y, 4.f);
  EXPECT_FLOAT_EQ(result_vertices[0].position().z, 6.f);

  EXPECT_FLOAT_EQ(result_vertices[1].position().x, 8.f);
  EXPECT_FLOAT_EQ(result_vertices[1].position().y, 10.f);
  EXPECT_FLOAT_EQ(result_vertices[1].position().z, 12.f);
}
}  // namespace s21
