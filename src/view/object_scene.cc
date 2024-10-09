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

void ObjectScene::allocateMemory() { scene_ = new QtSceneDrawer; }

void ObjectScene::initView() {
  scene_->setMinimumSize(1000, 800);
  grid_->addWidget(scene_);

  connect(scene_, &QtSceneDrawer::mousePress, this, &ObjectScene::onMousePress);
  connect(scene_, &QtSceneDrawer::mouseMove, this, &ObjectScene::onMouseMove);
  connect(scene_, &QtSceneDrawer::mouseWheel, this, &ObjectScene::onMouseWheel);
}

// void ObjectScene::drawScene(const QString &path) {
void ObjectScene::drawScene() { scene_->initModel(nullptr); }

void ObjectScene::imageSave(const QString &path, const QString &format) {
  (void)path;
  (void)format;
}

void ObjectScene::gifSave(const QString &path) { (void)path; }

void ObjectScene::clearScene() {}

void ObjectScene::onMousePress(QMouseEvent *event) {
  startPos = event->pos();

  if (event->button() == Qt::LeftButton) {
    leftMouse = true;
    rightMouse = false;
  } else if (event->button() == Qt::RightButton) {
    leftMouse = false;
    rightMouse = true;
  } else {
    leftMouse = false;
    rightMouse = false;
  }
}

void ObjectScene::onMouseMove(QMouseEvent *event) {
  bool shiftPressed = event->modifiers() & Qt::ShiftModifier;
  QPoint offset = event->pos() - startPos;

  if (leftMouse) {
    if (shiftPressed) {
      data_.move_x += offset.x() / 2;
      emit mouseEvent();
      data_.move_y -= offset.y() / 2; 
      emit mouseEvent();
    } else {
      if(std::abs(data_.rotate_x) == 360) {
        data_.rotate_x = 0;
      }
      if(std::abs(data_.rotate_y) == 360) {
        data_.rotate_y = 0;
      }
      data_.rotate_x += offset.y() / 2;
      emit mouseEvent();
      data_.rotate_y += offset.x() / 2;
      emit mouseEvent();
    }
  } else if (rightMouse) {
    if (shiftPressed) {
      data_.move_x += offset.x() / 2;
      emit mouseEvent();
      data_.move_z -= offset.y() / 2; 
      emit mouseEvent();
    } else {
      if(std::abs(data_.rotate_y) == 360) {
        data_.rotate_y = 0;
      }
      if(std::abs(data_.rotate_z) == 360) {
        data_.rotate_z = 0;
      }
      data_.rotate_y += offset.x() / 2;
      emit mouseEvent();
      data_.rotate_z += offset.y() / 2;
      emit mouseEvent();
    }
  }

  startPos = event->pos();

}

void ObjectScene::onMouseWheel(QWheelEvent *event) {
  if(event->angleDelta().y()) {
    Data::data().scale += 0.05;
  } else {
    Data::data().scale -= 0.05;
  }
  
  emit mouseEvent();
}

}  // namespace s21
