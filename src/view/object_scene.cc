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

ObjectScene::ObjectScene() : QWidget{} {
  allocateMemory();
  initView();
}

ObjectScene::~ObjectScene() {
  delete scene_;
}

void ObjectScene::allocateMemory() {}

void ObjectScene::initView() {}
