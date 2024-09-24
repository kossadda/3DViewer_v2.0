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

#include "include/model/base_file_reader.h"

namespace s21 {
class FileReader : public BaseFileReader {
 public:
 private:
  Scene ReadScene(const std::string& path,
                  const NormalizationParameters& params) override;
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_FILE_READER_H_
