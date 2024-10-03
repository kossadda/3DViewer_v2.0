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

#include "include/model/base_file_reader.h"

namespace s21 {
class FileReader : public BaseFileReader {
 public:
  Scene ReadScene(const std::string& path,
                  const NormalizationParameters& params) override;

 private:
  Vertex ParseVertex(const std::string& line) noexcept;
  std::vector<int>& ParseFace(const std::string& line) noexcept;
  // std::vector<std::string> ReadLines(const std::string& path);
  // std::vector<Vertex> ParseVertices(const std::vector<std::string>& lines);
  // std::vector<Edge> ParseEdges(const std::vector<std::string>& lines,
  //                              const std::vector<Vertex> vertices);

  float Normalize(float value, const NormalizationParameters& params,
                  const bool is_x_axis);
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_FILE_READER_H_
