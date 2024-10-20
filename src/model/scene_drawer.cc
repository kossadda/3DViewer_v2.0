/**
 * @file scene_drawer.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief Implementation file for the SceneDrawer class
 * @version 1.0
 * @date 2024-10-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/scene_drawer.h"

namespace s21 {

/**
 * @brief Constructor.
 *
 * Initializes the SceneDrawer and sets up OpenGL context for rendering.
 */
SceneDrawer::SceneDrawer() : gl_{new OpenGL} {
  QGridLayout *grid{new QGridLayout};
  grid->addWidget(gl_);
  setLayout(grid);

  connect(gl_, &OpenGL::mousePress, this, &SceneDrawer::mousePressEvent);
  connect(gl_, &OpenGL::mouseMove, this, &SceneDrawer::mouseMoveEvent);
  connect(gl_, &OpenGL::mouseWheel, this, &SceneDrawer::wheelEvent);
  connect(gl_, &OpenGL::recorded, this, &SceneDrawer::onRecorded);
}

/**
 * @brief Destructor.
 *
 * Cleans up any allocated resources, including the OpenGL context.
 */
SceneDrawer::~SceneDrawer() { delete gl_; }

/**
 * @brief Renders a 3D scene.
 *
 * This method takes a Scene object and renders it using OpenGL. It overrides
 * the pure virtual method from SceneDrawerBase.
 *
 * @param scene A pointer to the Scene object to be drawn.
 */
void SceneDrawer::drawScene(Scene *scene) {
  static CalculateType prev_mode{CalculateType::CPU};

  if (scene) {
    if (prev_mode != Data::data().calculate_type) {
      gl_->destroyBuffers();
    }

    if (gl_->isBufferAllocate()) {
      if (Data::data().calculate_type == CalculateType::CPU) {
        gl_->updateBuffer(scene);
        prev_mode = CalculateType::CPU;
      } else {
        prev_mode = CalculateType::GPU;
      }
    } else {
      gl_->destroyBuffers();
      gl_->initBuffers(scene);
    }
  }

  gl_->update();
}

/**
 * @brief Saves the current scene as an image.
 *
 * Exports the currently rendered scene to an image file at the specified path
 * in the provided format (e.g., PNG, JPG).
 *
 * @param path The file path where the image will be saved.
 * @param format The format of the image (e.g., "png", "jpg").
 */
void SceneDrawer::saveImage(const std::string &path, const std::string format) {
  gl_->createImage(path, format);
}

/**
 * @brief Saves the current scene as a GIF.
 *
 * Exports the currently rendered scene as a GIF file at the specified path.
 *
 * @param path The file path where the GIF will be saved.
 */
void SceneDrawer::saveGif(const std::string &path) { gl_->createGif(path); }

/**
 * @brief Clears the current scene.
 *
 * Removes all elements from the scene and resets the view.
 */
void SceneDrawer::clearScene() {
  gl_->destroyBuffers();
  gl_->update();
}

/**
 * @brief Handles mouse press events.
 *
 * Processes mouse press events, typically for rotating or interacting with
 * the scene.
 *
 * @param event A pointer to the QMouseEvent object representing the mouse press
 * event.
 */
void SceneDrawer::mousePressEvent(QMouseEvent *event) {
  emit mousePress(event);
}

/**
 * @brief Handles mouse move events.
 *
 * Processes mouse movement events, typically for rotating or panning the scene.
 *
 * @param event A pointer to the QMouseEvent object representing the mouse move
 * event.
 */
void SceneDrawer::mouseMoveEvent(QMouseEvent *event) { emit mouseMove(event); }

/**
 * @brief Handles mouse wheel events.
 *
 * Processes mouse wheel events for zooming in or out of the scene.
 *
 * @param event A pointer to the QWheelEvent object representing the wheel
 * event.
 */
void SceneDrawer::wheelEvent(QWheelEvent *event) { emit mouseWheel(event); }

/**
 * @brief Slot triggered when GIF recording is finished.
 *
 * This slot is called after a GIF has been successfully recorded.
 */
void SceneDrawer::onRecorded() { emit recorded(); }

}  // namespace s21
