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

#include "tests/include/file_reader_test.h"

namespace s21 {

TEST_F(FileReaderTest, test_1) {
  add_scene("./tests/data/test_1.obj");

  add_vertex(1, 2, 3);
  add_vertex(4, 5, 6);

  add_face({1, 2, 3});

  compare_scene();
}

TEST_F(FileReaderTest, test_2) {
  add_scene("./tests/data/test_2.obj");

  add_vertex(1, 2, 3);
  add_vertex(4, 5, 6);
  add_vertex(7, 8, 9);
  add_vertex(10, 11, 12);

  add_face({1, 2, 3});
  add_face({2, 3, 4});
  add_face({3, 4, 1});

  compare_scene();
}

TEST_F(FileReaderTest, test_3) {
  add_scene("./tests/data/test_3.obj");

  add_vertex(-1, -2, -3);
  add_vertex(-4, -5, -6);
  add_vertex(-7, -8, -9);

  add_face({1, 2, 3});

  compare_scene();
}

TEST_F(FileReaderTest, test_4) {
  add_scene("./tests/data/test_4.obj");

  add_vertex(0.1, 0.2, 0.3);
  add_vertex(0.4, 0.5, 0.6);
  add_vertex(0.7, 0.8, 0.9);

  add_face({1, 2, 3});

  compare_scene();
}

TEST_F(FileReaderTest, invalid_1) {
  EXPECT_THROW(add_scene("./tests/data/invalid_1.obj"), std::invalid_argument);
}

TEST_F(FileReaderTest, invalid_2) {
  EXPECT_THROW(add_scene("./tests/data/invalid_2.obj"), std::invalid_argument);
}

TEST_F(FileReaderTest, invalid_3) {
  EXPECT_THROW(add_scene("./tests/data/invalid_3.obj"), std::invalid_argument);
}

}  // namespace s21
