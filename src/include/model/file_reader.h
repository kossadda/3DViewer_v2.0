/**
 * @file file_reader.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief  Defines the FileReader class responsible for reading and parsing 3D
 * scene files
 * @version 1.0
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_FILE_READER_H_
#define SRC_INCLUDE_MODEL_FILE_READER_H_

#include <string>
#include <vector>

#include "include/model/file_reader_base.h"

namespace s21 {

/**
 * @class FileReader
 * @brief A class responsible for reading 3D scene files and parsing vertex and
 * face data.
 *
 * Inherits from FileReaderBase and provides implementation for reading scenes
 * from file paths. This class handles the parsing of vertices and faces and
 * supports normalization of parameters.
 */
class FileReader : public FileReaderBase {
 public:
  Scene* ReadScene(const std::string& path) override;

 private:
  Vertex ParseVertex(const std::string& line);
  std::vector<int> ParseFace(const std::string& line) const;

  float normalize_param_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_FILE_READER_H_
