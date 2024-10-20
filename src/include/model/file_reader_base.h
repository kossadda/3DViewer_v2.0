/**
 * @file file_reader_base.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Defines the base class for file readers responsible for loading 3D
 * scenes
 * @version 1.0
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_FILE_READER_BASE_H_
#define SRC_INCLUDE_MODEL_FILE_READER_BASE_H_

#include <string>

#include "include/model/scene.h"

namespace s21 {

/**
 * @class FileReaderBase
 * @brief Abstract base class for file readers that load 3D scenes from files.
 *
 * This class provides an interface for reading scene files and defines a
 * pure virtual function that derived classes must implement to handle specific
 * file formats.
 */
class FileReaderBase {
 public:
  virtual ~FileReaderBase() = default;
  virtual Scene* ReadScene(const std::string& path) = 0;
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_FILE_READER_BASE_H_
