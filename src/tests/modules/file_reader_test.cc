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

  // EXPECT_EQ(edge2[0].begin(), vertex2[1]);
  // std::cout << edge2[0].begin().position().x << std::endl;
  // std::cout << vertex2[0].position().x << std::endl;
  // EXPECT_EQ(edge2[0].end(), vertex2[1]);
  // EXPECT_EQ(edge2[1].begin(), vertex2[1]);
  // EXPECT_EQ(edge2[1].end(), vertex2[2]);
  // EXPECT_EQ(edge2[2].begin(), vertex2[2]);
  // EXPECT_EQ(edge2[2].end(), vertex2[0]);

  std::remove(path.c_str());
}

//   // Проверка корректности вершин
//   EXPECT_FLOAT_EQ(figure.vertices()[0].position().x, 0.288236f);
//   EXPECT_FLOAT_EQ(figure.vertices()[0].position().y, 0.185213f);
//   EXPECT_FLOAT_EQ(figure.vertices()[0].position().z, 1.545897f);

//   EXPECT_FLOAT_EQ(figure.vertices()[1].position().x, 0.257309f);
//   EXPECT_FLOAT_EQ(figure.vertices()[1].position().y, 0.009730f);
//   EXPECT_FLOAT_EQ(figure.vertices()[1].position().z, 1.185200f);

//   EXPECT_FLOAT_EQ(figure.vertices()[2].position().x, 0.289416f);
//   EXPECT_FLOAT_EQ(figure.vertices()[2].position().y, 0.128668f);
//   EXPECT_FLOAT_EQ(figure.vertices()[2].position().z, 1.506040f);

//   // Проверка корректности рёбер
//   EXPECT_EQ(figure.edges()[0].begin().position(),
//             figure.vertices()[0].position());
//   EXPECT_EQ(figure.edges()[0].end().position(),
//             figure.vertices()[1].position());

//   EXPECT_EQ(figure.edges()[1].begin().position(),
//             figure.vertices()[1].position());
//   EXPECT_EQ(figure.edges()[1].end().position(),
//             figure.vertices()[2].position());

//   EXPECT_EQ(figure.edges()[2].begin().position(),
//             figure.vertices()[2].position());
//   EXPECT_EQ(figure.edges()[2].end().position(),
//             figure.vertices()[0].position());
// }

// >>>>>>> develop
// TEST(FileReaderTest, ReadLinesCorrectly) {
//   s21::FileReader reader;
//   std::string path = "tests/data/test_1.obj";
//   std::vector<std::string> expected{
//       "v 1.0 2.0 3.0", "f 631/648/631 535/544/535 538/547/538 632/649/632",
//       "vf 1.2 2.1 2.1"};
//   std::vector<std::string> lines = reader.ReadLines(path);
//   EXPECT_EQ(expected, lines);
// }

// TEST(FileReaderTest, ReadLinesFileNotFound) {
//   s21::FileReader reader;
//   std::string path = "file.txt";
//   std::vector<std::string> lines = reader.ReadLines(path);

//   EXPECT_TRUE(lines.empty());
// }

// TEST(FileReaderTest, ParseVerticesEmptyLines) {
//   s21::FileReader reader;
//   std::vector<std::string> lines;
//   s21::NormalizationParameters params;
//   std::vector<s21::Vertex> vertices = reader.ParseVertices(lines);

//   EXPECT_TRUE(vertices.empty());
// }

// TEST(FileReaderTest, ParseEdges) {
//   s21::FileReader reader;
//   std::vector<std::string> line{
//       "v 0.288236 0.185213 1.545897", "v 0.257309 0.009730 1.185200",
//       "v 0.289416 0.128668 1.506040", "f 1/107/30 2/108/29 3/109/56"};
//   std::vector<s21::Vertex> vertices = reader.ParseVertices(line);
//   std::vector<s21::Edge> edges = reader.ParseEdges(line, vertices);
//   EXPECT_EQ(vertices.size(), 3);
//   EXPECT_EQ(edges.size(), 3);
//   std::cout << vertices[0].position_.x << std::endl;
//   std::cout << edges[0].begin_.position_.x << std::endl;
// }

// TEST(FileReaderTest, ReadVerticesFromString_1) {
//   s21::FileReader reader;

//   std::vector<std::string> line{"v 0.226476 2.097269 -1.624995"};
//   std::vector<s21::Vertex> vertices = reader.ParseVertices(line);

//   EXPECT_EQ(vertices.size(), 1);
//   EXPECT_FLOAT_EQ(vertices[0].position().x, 0.226476);
//   EXPECT_FLOAT_EQ(vertices[0].position().y, 2.097269);
//   EXPECT_FLOAT_EQ(vertices[0].position().z, -1.624995);
// }

// TEST(FileReaderTest, ReadVerticesFromString_3) {
//   s21::FileReader reader;

//   std::vector<std::string> line{
//       "v 0.232584 0.019179 -1.403350", "v 0.237516 -0.007116 -1.403348",
//       "v 0.225508 2.208368 1.555441",  "v 0.225450 2.187187 1.598367",
//       "v 0.266085 2.170335 1.564792",  "v 0.226661 2.202096 -1.566456",
//       "v 0.226536 2.128565 -1.619556", "v 0.250823 2.210459 -1.570653",
//       "v 0.273243 2.156695 -1.547029", "v 0.225759 0.052562 -1.619993",
//       "v 0.222545 0.051845 1.613612",  "v 0.262916 0.049758 1.619629",
//       "v 0.257309 0.009730 1.403353",  "v 0.261940 0.017199 1.185200"};
//   std::vector<s21::Vertex> vertices = reader.ParseVertices(line);

//   EXPECT_EQ(vertices.size(), 14);
//   EXPECT_FLOAT_EQ(vertices[0].position().x, 0.232584);
//   EXPECT_FLOAT_EQ(vertices[0].position().y, 0.019179);
//   EXPECT_FLOAT_EQ(vertices[0].position().z, -1.403350);

//   EXPECT_FLOAT_EQ(vertices[1].position().x, 0.237516);
//   EXPECT_FLOAT_EQ(vertices[1].position().y, -0.007116);
//   EXPECT_FLOAT_EQ(vertices[1].position().z, -1.403348);

//   EXPECT_FLOAT_EQ(vertices[2].position().x, 0.225508);
//   EXPECT_FLOAT_EQ(vertices[2].position().y, 2.208368);
//   EXPECT_FLOAT_EQ(vertices[2].position().z, 1.555441);

//   EXPECT_FLOAT_EQ(vertices[3].position().x, 0.225450);
//   EXPECT_FLOAT_EQ(vertices[3].position().y, 2.187187);
//   EXPECT_FLOAT_EQ(vertices[3].position().z, 1.598367);

//   EXPECT_FLOAT_EQ(vertices[4].position().x, 0.266085);
//   EXPECT_FLOAT_EQ(vertices[4].position().y, 2.170335);
//   EXPECT_FLOAT_EQ(vertices[4].position().z, 1.564792);

//   EXPECT_FLOAT_EQ(vertices[5].position().x, 0.226661);
//   EXPECT_FLOAT_EQ(vertices[5].position().y, 2.202096);
//   EXPECT_FLOAT_EQ(vertices[5].position().z, -1.566456);

//   EXPECT_FLOAT_EQ(vertices[6].position().x, 0.226536);
//   EXPECT_FLOAT_EQ(vertices[6].position().y, 2.128565);
//   EXPECT_FLOAT_EQ(vertices[6].position().z, -1.619556);

//   EXPECT_FLOAT_EQ(vertices[7].position().x, 0.250823);
//   EXPECT_FLOAT_EQ(vertices[7].position().y, 2.210459);
//   EXPECT_FLOAT_EQ(vertices[7].position().z, -1.570653);

//   EXPECT_FLOAT_EQ(vertices[8].position().x, 0.273243);
//   EXPECT_FLOAT_EQ(vertices[8].position().y, 2.156695);
//   EXPECT_FLOAT_EQ(vertices[8].position().z, -1.547029);

//   EXPECT_FLOAT_EQ(vertices[9].position().x, 0.225759);
//   EXPECT_FLOAT_EQ(vertices[9].position().y, 0.052562);
//   EXPECT_FLOAT_EQ(vertices[9].position().z, -1.619993);

//   EXPECT_FLOAT_EQ(vertices[10].position().x, 0.222545);
//   EXPECT_FLOAT_EQ(vertices[10].position().y, 0.051845);
//   EXPECT_FLOAT_EQ(vertices[10].position().z, 1.613612);

//   EXPECT_FLOAT_EQ(vertices[11].position().x, 0.262916);
//   EXPECT_FLOAT_EQ(vertices[11].position().y, 0.049758);
//   EXPECT_FLOAT_EQ(vertices[11].position().z, 1.619629);

//   EXPECT_FLOAT_EQ(vertices[12].position().x, 0.257309);
//   EXPECT_FLOAT_EQ(vertices[12].position().y, 0.009730);
//   EXPECT_FLOAT_EQ(vertices[12].position().z, 1.403353);

//   EXPECT_FLOAT_EQ(vertices[13].position().x, 0.261940);
//   EXPECT_FLOAT_EQ(vertices[13].position().y, 0.017199);
//   EXPECT_FLOAT_EQ(vertices[13].position().z, 1.185200);
// }

// TEST(FileReaderTest, ReadVerticesFromFile_0) {
//   s21::FileReader reader;

//   std::string path{"tests/data/model_1.obj"};
//   std::vector<std::string> line = reader.ReadLines(path);
//   std::vector<s21::Vertex> vertices = reader.ParseVertices(line);

//   EXPECT_EQ(vertices.size(), 1);
//   EXPECT_FLOAT_EQ(vertices[0].position().x, 0.287325);
//   EXPECT_FLOAT_EQ(vertices[0].position().y, 0.183571);
//   EXPECT_FLOAT_EQ(vertices[0].position().z, -1.538425);
// }

// TEST(FileReaderTest, ReadVerticesFromFile_InvalidFormat_1) {
//   s21::FileReader reader;

//   std::ofstream temp_file("tests/data/invalid.obj");
//   temp_file << "v 0.183571a 0.287325 0.287325";
//   temp_file.close();

//   std::ifstream file("tests/data/invalid.obj");
//   ASSERT_TRUE(file.is_open());

//   EXPECT_THROW(reader.ReadVertices(file), std::runtime_error);

//   file.close();
// }

// TEST(FileReaderTest, ReadVerticesFromFile_InvalidFormat_2) {
//   s21::FileReader reader;

//   std::ofstream temp_file("tests/data/invalid.obj");
//   temp_file << "v 0.183571 0.287325w 0.287325";
//   temp_file.close();

//   std::ifstream file("tests/data/invalid.obj");
//   ASSERT_TRUE(file.is_open());

//   EXPECT_THROW(reader.ReadVertices(file), std::runtime_error);

//   file.close();
// }

// TEST(FileReaderTest, ReadVerticesFromFile_InvalidFormat_3) {
//   s21::FileReader reader;

//   std::ofstream temp_file("tests/data/invalid.obj");
//   temp_file << "v 0.183571 0.287325 0.287325ewq";
//   temp_file.close();

//   std::ifstream file("tests/data/invalid.obj");
//   ASSERT_TRUE(file.is_open());

//   EXPECT_THROW(reader.ReadVertices(file), std::runtime_error);

//   file.close();
// }

// TEST(FileReaderTest, ReadVerticesFromFile_InvalidFormat_4) {
//   s21::FileReader reader;

//   std::ofstream temp_file("tests/data/invalid.obj");
//   temp_file << "v 0.183571";
//   temp_file.close();

//   std::ifstream file("tests/data/invalid.obj");
//   ASSERT_TRUE(file.is_open());

//   EXPECT_THROW(reader.ReadVertices(file), std::runtime_error);

//   file.close();
// }

// TEST(FileReaderTest, ReadVerticesFromFile_InvalidFormat_5) {
//   s21::FileReader reader;

//   std::ofstream temp_file("tests/data/invalid.obj");
//   temp_file << "v ";
//   temp_file.close();

//   std::ifstream file("tests/data/invalid.obj");
//   ASSERT_TRUE(file.is_open());

//   EXPECT_THROW(reader.ReadVertices(file), std::runtime_error);

//   file.close();
// }
