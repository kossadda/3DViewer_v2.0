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
/// @note Строка парсится дважды: 1) В ParseVerticals, 2)в ParseEdges.
/// @note Может удалять вершины в ParseVerticals?
Scene FileReader::ReadScene(const std::string& path,
                            const NormalizationParameters& params) {
  Scene scene;
  std::ifstream file{path};
  std::string line;
  std::vector<Vertex> vertices;

  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file " << path << std::endl;
    return scene;
  }

  while (std::getline(file, line)) {
    if (line.compare(0, 2, "v ") == 0) {
      vertices.emplace_back(ParseVertex(line));
    } else if (line.compare(0, 2, "f ") == 0) {
      std::vector<int> vertex_indices = ParseFace(line);
      std::vector<Edge> edges =
          CreateEdgesFromIndices(vertex_indices, vertices);
      Figure figure{vertices, edges};
      scene.AddFigure(figure);
    }
  }

  file.close();

  return scene;
}

Vertex FileReader::ParseVertex(const std::string& line) noexcept {
  std::istringstream iss{line};
  float x, y, z;
  iss.ignore(2);

  if (iss >> x >> y >> z) {
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
    size_t delimiter_pos = vertex_info.find('/');
    std::string tmp = vertex_info.substr(0, delimiter_pos);

    vertex_indices.emplace_back(std::stoi(tmp));
  }

  return vertex_indices;
}

std::vector<Edge> FileReader::CreateEdgesFromIndices(
    const std::vector<int>& vertex_indices,
    const std::vector<Vertex>& vertices) {
  std::vector<Edge> edges;

  for (size_t i = 0; i < vertex_indices.size(); ++i) {
    int current_index = vertex_indices[i] - 1;
    int next_index = vertex_indices[(i + 1) % vertex_indices.size()] - 1;
    edges.emplace_back(Edge{vertices[current_index], vertices[next_index]});
  }

  return edges;
}

float FileReader::Normalize(float value, const NormalizationParameters& params,
                            const bool is_x_axis) {
  float step = (is_x_axis) ? params.dx_step_ : params.dy_step_;

  return ((value - params.min_) / (params.max_ - params.min_)) * step;
}

}  // namespace s21
