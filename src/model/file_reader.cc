/**
 * @file file_reader.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Implementation file for the FileReader class
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

/**
 * @brief Reads a 3D scene from the given file path.
 *
 * This function opens and reads the scene data from the specified file path.
 * The data is parsed into a Scene object, which is returned to the caller.
 *
 * @param path The file path to the scene file.
 * @return Scene* A pointer to the parsed Scene object.
 */
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

  if (!vertices.size()) {
    throw std::invalid_argument("Empty file");
  }

  return new Scene{indices, vertices, normalize_param_};
}

/**
 * @brief Parses a line of text to extract vertex data.
 *
 * This function takes a string representing a line from the scene file and
 * parses it to extract vertex data (e.g., position coordinates).
 *
 * @param line The line of text containing vertex data.
 * @return Vertex The parsed vertex object.
 */
Vertex FileReader::ParseVertex(const std::string& line) {
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
  } else {
    throw std::invalid_argument("Invalid file");
  }

  if (!(iss >> std::ws).eof()) {
    throw std::invalid_argument("Invalid vertex format");
  }

  return Vertex{x, y, z};
}

/**
 * @brief Parses a line of text to extract face data.
 *
 * This function takes a string representing a line from the scene file and
 * parses it to extract face data, which is represented as a vector of vertex
 * indices.
 *
 * @param line The line of text containing face data.
 * @return std::vector<int> A vector of vertex indices that define the face.
 */
std::vector<int> FileReader::ParseFace(const std::string& line) {
  std::istringstream iss{line};
  std::vector<int> vertex_indices;
  iss.ignore(2);

  std::string vertex_info;
  while (iss >> vertex_info) {
    try {
      vertex_indices.emplace_back(std::stoi(vertex_info) - 1);
    } catch (const std::invalid_argument&) {
      throw std::invalid_argument("Invalid face format");
    }

    if (vertex_indices.size() > 1) {
      vertex_indices.emplace_back(vertex_indices.back());
    }
  }

  if (vertex_indices.size()) {
    vertex_indices.emplace_back(vertex_indices.front());
  }

  if (!(iss >> std::ws).eof()) {
    throw std::invalid_argument("Invalid face format");
  }

  return vertex_indices;
}

}  // namespace s21
