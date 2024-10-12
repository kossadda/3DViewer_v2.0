/**
 * @file file_reader.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/file_reader.h"

#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>

namespace s21 {

Scene* FileReader::ReadScene(const std::string& path) {
  std::ifstream file{path};
  std::string line;
  std::vector<Vertex> vertices;
  std::vector<int> indices;
  normalize_param_ = 1.0f;

  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file " << path << std::endl;
  }

  while (std::getline(file, line)) {
    if (line.compare(0, 2, "v ") == 0) {
      vertices.emplace_back(ParseVertex(line));
    } else if (line.compare(0, 2, "f ") == 0) {
      std::vector<int> face{ParseFace(line)};
      indices.insert(indices.end(), face.begin(), face.end());
    }
  }

  file.close();

  return new Scene{indices, vertices, normalize_param_};
}

Vertex FileReader::ParseVertex(const std::string& line) noexcept {
  std::istringstream iss{line};
  float x, y, z;
  iss.ignore(2);

  if (iss >> x >> y >> z) {
    if (std::abs(x) > normalize_param_) {
      normalize_param_ = x;
    }

    if (std::abs(y) > normalize_param_) {
      normalize_param_ = y;
    }

    if (std::abs(z) > normalize_param_) {
      normalize_param_ = z;
    }

    return Vertex{x, y, z};
  }

  return Vertex{};
}

std::vector<int> FileReader::ParseFace(const std::string& line) noexcept {
  std::istringstream iss{line};
  std::vector<int> vertex_indices;
  iss.ignore(2);

  std::string vertex_info;
  while (iss >> vertex_info) {
    vertex_indices.emplace_back(std::stoi(vertex_info) - 1);
    if (vertex_indices.size() > 1) {
      vertex_indices.emplace_back(vertex_indices.back());
    }
  }

  if (vertex_indices.size()) {
    vertex_indices.emplace_back(vertex_indices.front());
  }

  return vertex_indices;
}

}  // namespace s21
