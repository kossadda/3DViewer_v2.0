/**
 * @file reader_test.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#define private public
#include "include/model/file_reader.h"
#undef private

#include <fstream>
#include <iostream>
#include <sstream>

#include "../include/main.test.h"

TEST(FileReaderTest, ParseVertexCorrect) {
  s21::FileReader reader;
  std::string line{"v 0.288236 0.185213 1.545897"};
  s21::Vertex vertex = reader.ParseVertex(line);

  EXPECT_FLOAT_EQ(vertex.position().x, 0.288236);
  EXPECT_FLOAT_EQ(vertex.position().y, 0.185213);
  EXPECT_FLOAT_EQ(vertex.position().z, 1.545897);
}

TEST(FileReaderTest, ParseVertexIncorrect1) {
  s21::FileReader reader;
  std::string line{"v 0.185213 5.545897"};
  s21::Vertex vertex = reader.ParseVertex(line);

  EXPECT_FLOAT_EQ(vertex.position().x, 0);
  EXPECT_FLOAT_EQ(vertex.position().y, 0);
  EXPECT_FLOAT_EQ(vertex.position().z, .0);
}

TEST(FileReaderTest, ParseFaceCorrect) {
  s21::FileReader reader;
  std::string line{"f 224/107/30 189/108/29 299/109/56"};

  std::vector<int> indices = reader.ParseFace(line);

  EXPECT_EQ(indices[0], 224);
  EXPECT_EQ(indices[1], 189);
  EXPECT_EQ(indices[2], 299);
}

// TEST(FileReaderTest, CreateFromIndices) {
//   s21::FileReader reader;
//   std::vector<std::string> lines{
//       "v 0.288236 0.185213 1.545897", "v 0.257309 0.009730 1.185200",
//       "v 0.289416 0.128668 1.506040", "f 245/48/1 244/23/1 284/24/1
//       179/49/1"};

//   std::vector<s21::Vertex> vertices;

//   for (auto line : lines) {
//   }
// }

TEST(FileReaderTest, ReadSceneOneFigure) {
  s21::FileReader reader;
  s21::NormalizationParameters params;
  std::string path{"tests/data/test.obj"};
  std::vector<std::string> lines{
      "v 0.288236 0.185213 1.545897", "v 0.257309 0.009730 1.185200",
      "v 0.289416 0.128668 1.506040", "f 1/48/1 2/23/1 3/24/1"};

  std::ofstream test_file(path);
  for (const auto& line : lines) {
    test_file << line << std::endl;
  }

  test_file.close();
  s21::Scene scene = reader.ReadScene(path, params);

  auto edge = scene.figures().front().edges();
  auto vertex = scene.figures().front().vertices();

  scene.figures();
  EXPECT_EQ(edge[0].begin(), vertex[0]);
  EXPECT_EQ(edge[0].end(), vertex[1]);

  EXPECT_EQ(edge[1].begin(), vertex[1]);
  EXPECT_EQ(edge[1].end(), vertex[2]);

  EXPECT_EQ(edge[2].begin(), vertex[2]);
  EXPECT_EQ(edge[2].end(), vertex[0]);

  std::remove(path.c_str());
}

TEST(FileReaderTest, ReadSceneTwoFigure) {
  s21::FileReader reader;
  s21::NormalizationParameters params;
  std::string path{"tests/data/test.obj"};
  std::vector<std::string> lines{
      "v 0.288236 0.185213 1.545897",  "v 0.257309 0.009730 1.185200",
      "v 0.289416 0.128668 1.506040",  "v 0.128494 0.067700 -1.630105",
      "v -1.999521 0.069781 1.518724", "v -1.983809 0.019215 -1.563283",
      "f 1/48/1 2/23/1 3/24/1",        "f 4/12/9 5/11/8 6/17/14 "};

  std::ofstream test_file(path);
  for (const auto& line : lines) {
    test_file << line << std::endl;
  }

  test_file.close();
  s21::Scene scene = reader.ReadScene(path, params);

  auto edge1 = scene.figures()[0].edges();
  auto vertex1 = scene.figures()[0].vertices();
  auto edge2 = scene.figures()[1].edges();
  auto vertex2 = scene.figures()[1].vertices();

  scene.figures();
  EXPECT_EQ(edge1[0].begin(), vertex1[0]);
  EXPECT_EQ(edge1[0].end(), vertex1[1]);
  EXPECT_EQ(edge1[1].begin(), vertex1[1]);
  EXPECT_EQ(edge1[1].end(), vertex1[2]);
  EXPECT_EQ(edge1[2].begin(), vertex1[2]);
  EXPECT_EQ(edge1[2].end(), vertex1[0]);

  std::remove(path.c_str());
}
