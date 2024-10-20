/**
 * @file scene_view.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief Implementation of the SceneView class
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/scene_view.h"

namespace s21 {

/**
 * @brief Constructs a SceneView object, initializes memory and the view layout.
 */
SceneView::SceneView() : BaseWidget{} {
  allocateMemory();
  initView();
}

/**
 * @brief Destructor for SceneView, deletes the controller.
 */
SceneView::~SceneView() { delete controller_; }

/**
 * @brief Allocates memory for the controller (Facade object).
 */
void SceneView::allocateMemory() { controller_ = new Facade; }

/**
 * @brief Sets up the view and connects necessary signals for user interaction.
 */
void SceneView::initView() {
  setMinimumSize(1000, 800);
  auto *view{controller_->getView()};
  grid_->addWidget(view);

  connectSignals(view);
}

/**
 * @brief Connects signals related to mouse events for the view.
 * @tparam View Template parameter for the view type.
 * @param view Pointer to the view component.
 */
template <typename View>
void SceneView::connectSignals(View *view) {
  connect(view, &View::mousePress, this, &SceneView::onMousePress);
  connect(view, &View::mouseMove, this, &SceneView::onMouseMove);
  connect(view, &View::mouseWheel, this, &SceneView::onMouseWheel);
  connect(view, &View::recorded, this, &SceneView::onRecorded);
}

/**
 * @brief Loads the 3D scene from the specified file path.
 * @param path Path to the scene file.
 */
void SceneView::loadScene(const QString &path) {
  try {
    controller_->loadScene(path.toStdString());
  } catch (const std::invalid_argument &exception) {
    QMessageBox::warning(this, "Error", exception.what());
  }
}

/**
 * @brief Renders the 3D scene and emits information about vertices and edges.
 */
void SceneView::drawScene() {
  controller_->drawScene();
  emit drawInfo(controller_->numberOfVerticies(), controller_->numberOfEdges());
}

/**
 * @brief Saves the current scene as an image in the specified format.
 * @param path Path to save the image.
 * @param format Image format (e.g., PNG, JPEG).
 */
void SceneView::imageSave(const QString &path, const QString &format) {
  controller_->saveImage(path.toStdString(), format.toStdString());
}

/**
 * @brief Saves the current scene as an animated GIF.
 * @param path Path to save the GIF.
 */
void SceneView::gifSave(const QString &path) {
  controller_->saveGif(path.toStdString());
}

/**
 * @brief Handles mouse press events, updating interaction state based on mouse
 * button.
 * @param event Mouse press event data.
 */
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

/**
 * @brief Handles mouse movement events, updating the scene transformation
 * (rotation, translation).
 * @param event Mouse movement event data.
 */
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

/**
 * @brief Handles mouse wheel events, scaling the scene in or out.
 * @param event Mouse wheel event data.
 */
void SceneView::onMouseWheel(QWheelEvent *event) {
  if (event->angleDelta().y() > 0) {
    Data::data().scale += 0.05;
  } else {
    Data::data().scale -= 0.05;
  }

  emit mouseEvent();
}

/**
 * @brief Slot that is triggered when a recording event occurs.
 */
void SceneView::onRecorded() { emit recorded(); }

}  // namespace s21
