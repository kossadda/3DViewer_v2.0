/**
 * @file base_file_reader.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_BASE_FILE_READER_H_
#define SRC_INCLUDE_MODEL_BASE_FILE_READER_H_

#include <string>

#include "include/model/base_file_reader.h"
#include "include/model/normalization.h"
#include "include/model/scene.h"

namespace s21 {
class BaseFileReader {
 public:
  virtual ~BaseFileReader() = default;
  virtual Scene ReadScene(const std::string& path,
                          const NormalizationParameters& params) = 0;
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_BASE_FILE_READER_H_
