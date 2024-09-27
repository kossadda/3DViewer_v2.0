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

#include <istream>
#include <string>
#include <vector>

#include "include/model/base_file_reader.h"

namespace s21 {
class FileReader : public BaseFileReader {
 public:
  Scene ReadScene(const std::string& path,
                  const NormalizationParameters& params) override;

 private:
  std::vector<Vertex> ReadVertices(std::istream& file);
  std::vector<Point3D> ReadNormals(std::istream& file);
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_FILE_READER_H_
