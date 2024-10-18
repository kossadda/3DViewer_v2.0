/**
 * @file file_reader_test.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_TESTS_INCLUDE_FILE_READER_TEST_H_
#define SRC_TESTS_INCLUDE_FILE_READER_TEST_H_

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/model/file_reader.h"

namespace s21 {

class FileReaderTest : public ::testing::Test {
 public:
  void add_face(const std::initializer_list<int> &face) {
    exp_i.emplace_back(int{*face.begin()} - 1);
    for (auto i{face.begin() + 1}; i != face.end(); ++i) {
      exp_i.emplace_back(int{*i} - 1);
      exp_i.emplace_back(int{*i} - 1);
    }
    exp_i.emplace_back(int{*face.begin()} - 1);
  }

  void add_vertex(float x, float y, float z) {
    exp_v.push_back({x, y, z});

    if (std::abs(x) > normalize) {
      normalize = x;
    }
    if (std::abs(y) > normalize) {
      normalize = y;
    }
    if (std::abs(z) > normalize) {
      normalize = z;
    }
  }

  void add_scene(const std::string &path) { scene = reader->ReadScene(path); }

  void normalize_vertices() {
    for (Vertex &vertex : exp_v) {
      vertex = vertex.Normalize(normalize);
    }
  }

  void compare_scene() {
    normalize_vertices();

    EXPECT_NE(scene, nullptr);
    EXPECT_EQ(scene->vertices().size(), exp_v.size());
    EXPECT_EQ(scene->indices().size(), exp_i.size());

    for (size_t i = 0; i < exp_v.size(); ++i) {
      EXPECT_NEAR(scene->vertices()[i].position().x, exp_v[i].position().x,
                  1e-6);
      EXPECT_NEAR(scene->vertices()[i].position().y, exp_v[i].position().y,
                  1e-6);
      EXPECT_NEAR(scene->vertices()[i].position().z, exp_v[i].position().z,
                  1e-6);
    }

    for (size_t i = 0; i < exp_i.size(); ++i) {
      EXPECT_EQ(scene->indices()[i], exp_i[i]);
    }
  }

 protected:
  void SetUp() override { reader = new FileReader(); }

  void TearDown() override {
    delete reader;
    delete scene;
  }

  FileReader *reader;
  Scene *scene{};
  std::vector<Vertex> exp_v;
  std::vector<int> exp_i;
  float normalize{1.0};
};

}  // namespace s21

#endif  // SRC_TESTS_INCLUDE_FILE_READER_TEST_H_
