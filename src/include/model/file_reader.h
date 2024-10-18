/**
 * @file file_reader.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
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

class FileReader : public FileReaderBase {
 public:
  Scene* ReadScene(const std::string& path) override;

 private:
  Vertex ParseVertex(const std::string& line);
  std::vector<int> ParseFace(const std::string& line);

  float normalize_param_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_FILE_READER_H_
