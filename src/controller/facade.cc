/**
 * @file facade.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/controller/facade.h"

namespace s21 {

Facade::Facade() {
  file_reader_ = new FileReader;
  scene_drawer_ = new SceneDrawer;
}

Facade::~Facade() {
  delete file_reader_;
  delete scene_drawer_;
  delete scene_;
}

void Facade::loadScene(const std::string &path) {
  scene_drawer_->clearScene();
  delete scene_;
  scene_ = file_reader_->ReadScene(path);
  drawScene();
}

void Facade::drawScene() {
  if (scene_) {
    scene_drawer_->drawScene(scene_);
  }
}

}  // namespace s21
