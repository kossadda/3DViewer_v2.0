/**
 * @file scene_view.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/scene_view.h"

namespace s21 {

SceneView::SceneView() : BaseWidget{} {
  allocateMemory();
  initView();
}

SceneView::~SceneView() { delete controller_; }

void SceneView::allocateMemory() { controller_ = new Facade; }

void SceneView::initView() {
  setMinimumSize(1000, 800);
  auto *view{controller_->getView()};
  grid_->addWidget(view);

  connectSignals(view);
}

template <typename View>
void SceneView::connectSignals(View *view) {
  connect(view, &View::mousePress, this, &SceneView::onMousePress);
  connect(view, &View::mouseMove, this, &SceneView::onMouseMove);
  connect(view, &View::mouseWheel, this, &SceneView::onMouseWheel);
  connect(view, &View::recorded, this, &SceneView::onRecorded);
}

void SceneView::loadScene(const QString &path) {
  try {
    controller_->loadScene(path.toStdString());
  } catch (const std::invalid_argument &exception) {
    QMessageBox::warning(this, "Error", exception.what());
  }
}

void SceneView::drawScene() {
  controller_->drawScene();
  emit drawInfo(controller_->numberOfVerticies(), controller_->numberOfEdges());
}

void SceneView::imageSave(const QString &path, const QString &format) {
  controller_->saveImage(path.toStdString(), format.toStdString());
}

void SceneView::gifSave(const QString &path) {
  controller_->saveGif(path.toStdString());
}

void SceneView::onMousePress(QMouseEvent *event) {
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

void SceneView::onMouseMove(QMouseEvent *event) {
  bool shiftPressed = event->modifiers() & Qt::ShiftModifier;
  QPoint offset = event->pos() - startPos;

  if (leftMouse) {
    if (shiftPressed) {
      data_.move_x += offset.x() / 2;
      emit mouseEvent();
      data_.move_y -= offset.y() / 2;
      emit mouseEvent();
    } else {
      if (std::abs(data_.rotate_x) == 360) {
        data_.rotate_x = 0;
      }
      if (std::abs(data_.rotate_y) == 360) {
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
      if (std::abs(data_.rotate_y) == 360) {
        data_.rotate_y = 0;
      }
      if (std::abs(data_.rotate_z) == 360) {
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

void SceneView::onMouseWheel(QWheelEvent *event) {
  if (event->angleDelta().y() > 0) {
    Data::data().scale += 0.05;
  } else {
    Data::data().scale -= 0.05;
  }

  emit mouseEvent();
}

void SceneView::onRecorded() { emit recorded(); }

}  // namespace s21
