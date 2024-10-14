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

SceneDrawer::SceneDrawer() : gl{new OpenGL} {
  QGridLayout *grid{new QGridLayout};
  grid->addWidget(gl);
  setLayout(grid);

  connect(gl, &OpenGL::mousePress, this, &SceneDrawer::mousePressEvent);
  connect(gl, &OpenGL::mouseMove, this, &SceneDrawer::mouseMoveEvent);
  connect(gl, &OpenGL::mouseWheel, this, &SceneDrawer::wheelEvent);
}

SceneDrawer::~SceneDrawer() { delete gl; }

void SceneDrawer::drawScene(Scene *scene) {
  if (gl->isBufferAllocate()) {
    if (Data::data().calculate_type == CalculateType::CPU) {
      gl->updateBuffer(scene);
    }
  } else {
    gl->destroyBuffers();
    gl->initBuffers(scene);
  }

  gl->update();
}

void SceneDrawer::clearScene() {
  gl->destroyBuffers();
  gl->update();
}

void SceneDrawer::mousePressEvent(QMouseEvent *event) {
  emit mousePress(event);
}

void SceneDrawer::mouseMoveEvent(QMouseEvent *event) { emit mouseMove(event); }

void SceneDrawer::wheelEvent(QWheelEvent *event) { emit mouseWheel(event); }

}  // namespace s21
