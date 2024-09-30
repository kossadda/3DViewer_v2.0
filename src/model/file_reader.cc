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
Scene FileReader::ReadScene(const std::string& path,
                            const NormalizationParameters& params) {
  std::vector<std::string> lines = ReadLines(path);
  std::vector<Vertex> vertices = ParseVertices(lines, params);
  std::vector<Edge> edges = ParseEdges(lines, vertices);
  Figure figure(vertices, edges);
  Scene scene;
  scene.AddFigure(figure);

  return scene;
}

/// @todo Решить как обрабатывать ошибки. Стоит ли выбрасывать исключения?
std::vector<std::string> FileReader::ReadLines(const std::string& path) {
  std::ifstream file(path);

  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file " << path << std::endl;
    return {};
  }

  std::vector<std::string> lines;
  std::string line;

  while (std::getline(file, line)) {
    if (line[0] == 'v' || line[0] == 'f') {
      lines.emplace_back(line);
    }
  }

  file.close();

  return lines;
}

std::vector<Vertex> FileReader::ParseVertices(
    const std::vector<std::string>& lines,
    const NormalizationParameters& params) {
  std::vector<Vertex> vertices;

  for (auto line : lines) {
    if (line.substr(0, 2) == "v ") {
      std::istringstream iss(line.substr(2));
      float x, y, z;

      if (iss >> x >> y >> z) {
        x = Normalize(x, params, true);
        y = Normalize(y, params, false);

        vertices.emplace_back(Vertex(x, y, z));
      }
    }
  }

  return vertices;
}

std::vector<Edge> FileReader::ParseEdges(const std::vector<std::string>& lines,
                                         const std::vector<Vertex> vertices) {
  std::vector<Edge> edges;

  for (auto line : lines) {
    if (line.substr(0, 2) == "f ") {
      std::istringstream iss(line.substr(2));
      std::vector<int> indices;
      int index;

      while (iss >> index) {
        indices.emplace_back(index - 1);
      }

      if (indices.size() >= 2) {
        for (size_t i = 0; i < indices.size(); ++i) {
          const Vertex& begin = vertices[indices[i]];
          const Vertex& end = vertices[indices[(i + 1) % indices.size()]];

          Edge edge{begin, end};
          edges.emplace_back(edge);
        }
      }
    }
  }

  return edges;
}

float FileReader::Normalize(float value, const NormalizationParameters& params,
                            const bool is_x_axis) {
  float step = (is_x_axis) ? params.dx_step_ : params.dy_step_;

  return ((value - params.min_) / (params.max_ - params.min_)) * step;
}

}  // namespace s21
