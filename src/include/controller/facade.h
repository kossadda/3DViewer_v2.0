/**
 * @file facade.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_CONTROLLER_FACADE_H_
#define SRC_INCLUDE_CONTROLLER_FACADE_H_

#include <string>

#include "include/model/base_file_reader.h"
#include "include/model/file_reader.h"
#include "include/model/qt_scene_drawer.h"
#include "include/model/scene.h"
#include "include/model/scene_drawer_base.h"

namespace s21 {
class Facade {
 public:
  Facade();
  ~Facade();

  void loadScene(const std::string &path);
  void drawScene();
  inline SceneDrawerBase *getView() { return scene_drawer_; }

 private:
  SceneDrawerBase *scene_drawer_;
  BaseFileReader *file_reader_;
  Scene *scene_{};
};
}  // namespace s21

#endif  // SRC_INCLUDE_CONTROLLER_FACADE_H_
