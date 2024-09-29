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
  std::vector<Edge> edges = ParseEdges(lines, params);
  Figure figure(vertices, edges);
  Scene scene;
  scene.AddFigure(figure);

  return scene;
}

/// @todo Решить как обрабатывать ошибки. Стоит ли выбрасывать исключения?
std::vector<std::string> FileReader::ReadLines(const std::string& path) {
  std::ifstream file(path);

  if (!file.is_open()) {
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

/// @todo Подумать над целесообразностью выбрасываемого исключения
/// @todo Заменить stringstream на istringstream
/// @note Так как в методе реализовано чтение из файла, то логичнее использовать
/// поток ввода, нежели ввода-вывода
std::vector<Vertex> FileReader::ReadVertices(std::istream& file) {
  std::vector<Vertex> vertices;
  std::string line;

  while (std::getline(file, line)) {
    if (line.substr(0, 2) == "v ") {
      std::stringstream ss(line.substr(2));
      float x, y, z;

      if (ss >> x >> y >> z) {
        vertices.emplace_back(Point3D{x, y, z});
      }
    }
  }

  if (vertices.empty()) {
    throw std::runtime_error("Error: failed to read vertices");
  }

  return vertices;
}
}  // namespace s21
