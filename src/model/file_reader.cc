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
#include <sstream>

namespace s21 {
Scene FileReader::ReadScene(const std::string& path,
                            const NormalizationParameters& params) {
  Scene s;

  return s;
}

std::vector<Vertex> FileReader::ReadVertices(std::istream& file) {
  std::vector<Vertex> vertices;
  std::string line;

  while (std::getline(file, line)) {
    if (line.empty() || line[0] != 'v' || line[1] != ' ') {
      continue;
    }

    std::stringstream ss(line.substr(2));

    float x, y, z;

    if (ss >> x >> y >> z) {
      vertices.emplace_back(Point3D{x, y, z});
    } else {
      throw std::runtime_error("Error: invalid vertex format in string: " +
                               line);
    }

    if (vertices.empty()) {
      throw std::runtime_error("Error: failed to read vertices");
    }
  }

  return vertices;
}
}  // namespace s21
