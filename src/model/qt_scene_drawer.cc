/**
 * @file qt_scene_drawer.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/qt_scene_drawer.h"

namespace s21 {

QtSceneDrawer::QtSceneDrawer() : gl{new OpenGL} {
  QGridLayout *grid{new QGridLayout};
  grid->addWidget(gl);
  setLayout(grid);

  connect(gl, &OpenGL::mousePress, this, &QtSceneDrawer::mousePressEvent);
  connect(gl, &OpenGL::mouseMove, this, &QtSceneDrawer::mouseMoveEvent);
  connect(gl, &OpenGL::mouseWheel, this, &QtSceneDrawer::wheelEvent);
}

QtSceneDrawer::~QtSceneDrawer() { delete gl; }

void QtSceneDrawer::drawScene(Scene *scene) {
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

void QtSceneDrawer::clearScene() {
  gl->destroyBuffers();
  gl->update();
}

void QtSceneDrawer::mousePressEvent(QMouseEvent *event) {
  emit mousePress(event);
}

void QtSceneDrawer::mouseMoveEvent(QMouseEvent *event) {
  emit mouseMove(event);
}

void QtSceneDrawer::wheelEvent(QWheelEvent *event) { emit mouseWheel(event); }

}  // namespace s21
