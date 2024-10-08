/**
 * @file object_scene.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/object_scene.h"

namespace s21 {

ObjectScene::ObjectScene() : BaseWidget{} {
  allocateMemory();
  initView();
}

void ObjectScene::allocateMemory() {
  scene_ = new QtSceneDrawer;
}

void ObjectScene::initView() {
  scene_->setMinimumSize(1000, 800);
  grid_->addWidget(scene_);
}

// void ObjectScene::drawScene(const QString &path) {
void ObjectScene::drawScene() {
  scene_->initModel(nullptr);
}

void ObjectScene::imageSave(const QString &path, const QString &format) {
  (void)path;
  (void)format;
}

void ObjectScene::gifSave(const QString &path) { (void)path; }

void ObjectScene::clearScene() {}

void ObjectScene::resetObject() {}

}  // namespace s21
