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

  connect(scene_drawer_, &SceneDrawerBase::recorded, this, &Facade::onRecorded);
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

void Facade::drawScene() { scene_drawer_->drawScene(scene_); }

void Facade::saveImage(const std::string &path, const std::string format) {
  scene_drawer_->saveImage(path, format);
}

void Facade::saveGif(const std::string &path) { scene_drawer_->saveGif(path); }

void Facade::onRecorded() { emit recorded(); }

std::size_t Facade::numberOfVerticies() {
  return (scene_) ? scene_->vertices().size() : 0;
}

std::size_t Facade::numberOfEdges() {
  return (scene_) ? scene_->indices().size() : 0;
}

}  // namespace s21
