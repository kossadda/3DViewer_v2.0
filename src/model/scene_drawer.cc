/**
 * @file scene_drawer.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/scene_drawer.h"

namespace s21 {

SceneDrawer::SceneDrawer() : gl_{new OpenGL} {
  QGridLayout *grid{new QGridLayout};
  grid->addWidget(gl_);
  setLayout(grid);

  connect(gl_, &OpenGL::mousePress, this, &SceneDrawer::mousePressEvent);
  connect(gl_, &OpenGL::mouseMove, this, &SceneDrawer::mouseMoveEvent);
  connect(gl_, &OpenGL::mouseWheel, this, &SceneDrawer::wheelEvent);
  connect(gl_, &OpenGL::recorded, this, &SceneDrawer::onRecorded);
}

SceneDrawer::~SceneDrawer() { delete gl_; }

void SceneDrawer::drawScene(Scene *scene) {
  if (scene) {
    if (gl_->isBufferAllocate()) {
      if (Data::data().calculate_type == CalculateType::CPU) {
        gl_->updateBuffer(scene);
      }
    } else {
      gl_->destroyBuffers();
      gl_->initBuffers(scene);
    }
  }

  gl_->update();
}

void SceneDrawer::saveImage(const std::string &path, const std::string format) {
  gl_->createImage(path, format);
}

void SceneDrawer::saveGif(const std::string &path) { gl_->createGif(path); }

void SceneDrawer::clearScene() {
  gl_->destroyBuffers();
  gl_->update();
}

void SceneDrawer::mousePressEvent(QMouseEvent *event) {
  emit mousePress(event);
}

void SceneDrawer::mouseMoveEvent(QMouseEvent *event) { emit mouseMove(event); }

void SceneDrawer::wheelEvent(QWheelEvent *event) { emit mouseWheel(event); }

void SceneDrawer::onRecorded() { emit recorded(); }

}  // namespace s21
