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

ObjectScene::ObjectScene() : BaseWidget{} {
  allocateMemory();
  initView();
}

void ObjectScene::allocateMemory() { scene_ = new QOpenGLWidget; }

void ObjectScene::initView() {
  scene_->setMinimumSize(1000, 800);
  grid_->addWidget(scene_);
}

void ObjectScene::drawScene(const QString& path) {
  (void)path;
}

void ObjectScene::saveImage(const QString & path) {
  (void)path;
}

void ObjectScene::saveGif(const QString & path) {
  (void)path;
}

void ObjectScene::clearScene() {

}

void ObjectScene::resetObject() {
  
}