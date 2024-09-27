/**
 * @file file_reader_test.cc
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
#include <sstream>

#include "../include/main.test.h"

TEST(FileReaderTest, ReadVerticesFromString_0) {
  s21::FileReader file_reader;

  std::istringstream data("v 0.284234 2.128049 1.438571");
  std::vector<s21::Vertex> vertices = file_reader.ReadVertices(data);

  EXPECT_EQ(vertices.size(), 1);
  EXPECT_FLOAT_EQ(vertices[0].position().x, 0.284234);
  EXPECT_FLOAT_EQ(vertices[0].position().y, 2.128049);
  EXPECT_FLOAT_EQ(vertices[0].position().z, 1.438571);
}

TEST(FileReaderTest, ReadVerticesFromString_1) {
  s21::FileReader file_reader;

  std::istringstream data("v 0.226476 2.097269 -1.624995");
  std::vector<s21::Vertex> vertices = file_reader.ReadVertices(data);

  EXPECT_EQ(vertices.size(), 1);
  EXPECT_FLOAT_EQ(vertices[0].position().x, 0.226476);
  EXPECT_FLOAT_EQ(vertices[0].position().y, 2.097269);
  EXPECT_FLOAT_EQ(vertices[0].position().z, -1.624995);
}

TEST(FileReaderTest, ReadVerticesFromString_2) {
  s21::FileReader file_reader;

  std::istringstream data(
      "v 0.261939 0.017199 -1.185200\n"
      "v 0.287325 0.183571 -1.538425\n"
      "v 0.289416 0.128668 -1.491969\n");
  std::vector<s21::Vertex> vertices = file_reader.ReadVertices(data);

  EXPECT_EQ(vertices.size(), 3);
  EXPECT_FLOAT_EQ(vertices[0].position().x, 0.261939);
  EXPECT_FLOAT_EQ(vertices[0].position().y, 0.017199);
  EXPECT_FLOAT_EQ(vertices[0].position().z, -1.185200);

  EXPECT_FLOAT_EQ(vertices[1].position().x, 0.287325);
  EXPECT_FLOAT_EQ(vertices[1].position().y, 0.183571);
  EXPECT_FLOAT_EQ(vertices[1].position().z, -1.538425);

  EXPECT_FLOAT_EQ(vertices[2].position().x, 0.289416);
  EXPECT_FLOAT_EQ(vertices[2].position().y, 0.128668);
  EXPECT_FLOAT_EQ(vertices[2].position().z, -1.491969);
}

TEST(FileReaderTest, ReadVerticesFromString_3) {
  s21::FileReader file_reader;

  std::istringstream data(
      "v 0.232584 0.019179 -1.403350\n"
      "v 0.237516 -0.007116 -1.403348\n"
      "v 0.225508 2.208368 1.555441\n"
      "v 0.225450 2.187187 1.598367\n"
      "v 0.266085 2.170335 1.564792\n"
      "v 0.226661 2.202096 -1.566456\n"
      "v 0.226536 2.128565 -1.619556\n"
      "v 0.250823 2.210459 -1.570653\n"
      "v 0.273243 2.156695 -1.547029\n"
      "v 0.225759 0.052562 -1.619993\n"
      "v 0.222545 0.051845 1.613612\n"
      "v 0.262916 0.049758 1.619629\n"
      "v 0.257309 0.009730 1.403353\n"
      "v 0.261940 0.017199 1.185200\n");
  std::vector<s21::Vertex> vertices = file_reader.ReadVertices(data);

  EXPECT_EQ(vertices.size(), 14);
  EXPECT_FLOAT_EQ(vertices[0].position().x, 0.232584);
  EXPECT_FLOAT_EQ(vertices[0].position().y, 0.019179);
  EXPECT_FLOAT_EQ(vertices[0].position().z, -1.403350);

  EXPECT_FLOAT_EQ(vertices[1].position().x, 0.237516);
  EXPECT_FLOAT_EQ(vertices[1].position().y, -0.007116);
  EXPECT_FLOAT_EQ(vertices[1].position().z, -1.403348);

  EXPECT_FLOAT_EQ(vertices[2].position().x, 0.225508);
  EXPECT_FLOAT_EQ(vertices[2].position().y, 2.208368);
  EXPECT_FLOAT_EQ(vertices[2].position().z, 1.555441);

  EXPECT_FLOAT_EQ(vertices[3].position().x, 0.225450);
  EXPECT_FLOAT_EQ(vertices[3].position().y, 2.187187);
  EXPECT_FLOAT_EQ(vertices[3].position().z, 1.598367);

  EXPECT_FLOAT_EQ(vertices[4].position().x, 0.266085);
  EXPECT_FLOAT_EQ(vertices[4].position().y, 2.170335);
  EXPECT_FLOAT_EQ(vertices[4].position().z, 1.564792);

  EXPECT_FLOAT_EQ(vertices[5].position().x, 0.226661);
  EXPECT_FLOAT_EQ(vertices[5].position().y, 2.202096);
  EXPECT_FLOAT_EQ(vertices[5].position().z, -1.566456);

  EXPECT_FLOAT_EQ(vertices[6].position().x, 0.226536);
  EXPECT_FLOAT_EQ(vertices[6].position().y, 2.128565);
  EXPECT_FLOAT_EQ(vertices[6].position().z, -1.619556);

  EXPECT_FLOAT_EQ(vertices[7].position().x, 0.250823);
  EXPECT_FLOAT_EQ(vertices[7].position().y, 2.210459);
  EXPECT_FLOAT_EQ(vertices[7].position().z, -1.570653);

  EXPECT_FLOAT_EQ(vertices[8].position().x, 0.273243);
  EXPECT_FLOAT_EQ(vertices[8].position().y, 2.156695);
  EXPECT_FLOAT_EQ(vertices[8].position().z, -1.547029);

  EXPECT_FLOAT_EQ(vertices[9].position().x, 0.225759);
  EXPECT_FLOAT_EQ(vertices[9].position().y, 0.052562);
  EXPECT_FLOAT_EQ(vertices[9].position().z, -1.619993);

  EXPECT_FLOAT_EQ(vertices[10].position().x, 0.222545);
  EXPECT_FLOAT_EQ(vertices[10].position().y, 0.051845);
  EXPECT_FLOAT_EQ(vertices[10].position().z, 1.613612);

  EXPECT_FLOAT_EQ(vertices[11].position().x, 0.262916);
  EXPECT_FLOAT_EQ(vertices[11].position().y, 0.049758);
  EXPECT_FLOAT_EQ(vertices[11].position().z, 1.619629);

  EXPECT_FLOAT_EQ(vertices[12].position().x, 0.257309);
  EXPECT_FLOAT_EQ(vertices[12].position().y, 0.009730);
  EXPECT_FLOAT_EQ(vertices[12].position().z, 1.403353);

  EXPECT_FLOAT_EQ(vertices[13].position().x, 0.261940);
  EXPECT_FLOAT_EQ(vertices[13].position().y, 0.017199);
  EXPECT_FLOAT_EQ(vertices[13].position().z, 1.185200);
}

TEST(FileReaderTest, ReadVerticesFromFile_0) {
  s21::FileReader file_reader;

  std::ifstream file("tests/data/model_1.obj");
  EXPECT_TRUE(file.is_open());
  std::vector<s21::Vertex> vertices = file_reader.ReadVertices(file);

  EXPECT_EQ(vertices.size(), 1);
  EXPECT_FLOAT_EQ(vertices[0].position().x, 0.287325);
  EXPECT_FLOAT_EQ(vertices[0].position().y, 0.183571);
  EXPECT_FLOAT_EQ(vertices[0].position().z, -1.538425);

  file.close();
}

TEST(FileReaderTest, ReadVerticesFromEmptyFile) {
  s21::FileReader file_reader;

  std::ifstream file("tests/data/empty.obj");
  EXPECT_TRUE(file.is_open());

  EXPECT_THROW(file_reader.ReadVertices(file), std::runtime_error);

  file.close();
}

TEST(FileReaderTest, ReadVerticesFromFile_InvalidFormat_0) {
  s21::FileReader file_reader;

  std::ofstream temp_file("tests/data/invalid.obj");
  temp_file << "v 0.287325 0.183571";
  temp_file.close();

  std::ifstream file("tests/data/invalid.obj");
  ASSERT_TRUE(file.is_open());

  EXPECT_THROW(file_reader.ReadVertices(file), std::runtime_error);

  file.close();
}

TEST(FileReaderTest, ReadVerticesFromFile_InvalidFormat_1) {
  s21::FileReader file_reader;

  std::ofstream temp_file("tests/data/invalid.obj");
  temp_file << "v 0.183571a 0.287325 0.287325";
  temp_file.close();

  std::ifstream file("tests/data/invalid.obj");
  ASSERT_TRUE(file.is_open());

  EXPECT_THROW(file_reader.ReadVertices(file), std::runtime_error);

  file.close();
}

TEST(FileReaderTest, ReadVerticesFromFile_InvalidFormat_2) {
  s21::FileReader file_reader;

  std::ofstream temp_file("tests/data/invalid.obj");
  temp_file << "v 0.183571 0.287325w 0.287325";
  temp_file.close();

  std::ifstream file("tests/data/invalid.obj");
  ASSERT_TRUE(file.is_open());

  EXPECT_THROW(file_reader.ReadVertices(file), std::runtime_error);

  file.close();
}

TEST(FileReaderTest, ReadVerticesFromFile_InvalidFormat_3) {
  s21::FileReader file_reader;

  std::ofstream temp_file("tests/data/invalid.obj");
  temp_file << "v 0.183571 0.287325 0.287325ewq";
  temp_file.close();

  std::ifstream file("tests/data/invalid.obj");
  ASSERT_TRUE(file.is_open());

  EXPECT_THROW(file_reader.ReadVertices(file), std::runtime_error);

  file.close();
}

TEST(FileReaderTest, ReadVerticesFromFile_InvalidFormat_4) {
  s21::FileReader file_reader;

  std::ofstream temp_file("tests/data/invalid.obj");
  temp_file << "v 0.183571";
  temp_file.close();

  std::ifstream file("tests/data/invalid.obj");
  ASSERT_TRUE(file.is_open());

  EXPECT_THROW(file_reader.ReadVertices(file), std::runtime_error);

  file.close();
}

TEST(FileReaderTest, ReadVerticesFromFile_InvalidFormat_5) {
  s21::FileReader file_reader;

  std::ofstream temp_file("tests/data/invalid.obj");
  temp_file << "v ";
  temp_file.close();

  std::ifstream file("tests/data/invalid.obj");
  ASSERT_TRUE(file.is_open());

  EXPECT_THROW(file_reader.ReadVertices(file), std::runtime_error);

  file.close();
}
