/**
 * @file qt_scene_drawer.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/qt_scene_drawer.h"

namespace s21 {

QtSceneDrawer::QtSceneDrawer() : QOpenGLWidget{} {
  initializeOpenGLFunctions();
  allocateMemory();
}

QtSceneDrawer::~QtSceneDrawer() {
  delete program_;
  delete vao_;
  delete vbo_;
  delete ebo_;
  delete rotate_;
  delete scale_;
  delete move_;
  delete projection_;
  delete camera_;
}

void QtSceneDrawer::allocateMemory() {
  program_ = new QOpenGLShaderProgram;
  vao_ = new QOpenGLVertexArrayObject;
  vbo_ = new QOpenGLBuffer;
  ebo_ = new QOpenGLBuffer;
  rotate_ = new QMatrix4x4;
  scale_ = new QMatrix4x4;
  move_ = new QMatrix4x4;
  projection_ = new QMatrix4x4;
  camera_ = new QMatrix4x4;
}

void QtSceneDrawer::drawScene(const Scene &scene) {
  initObject(scene);
  paintGL();
}

void QtSceneDrawer::initializeGL() { glEnable(GL_DEPTH_TEST); }

void QtSceneDrawer::initObject(const Scene &scene) {
  destroyBuffers();
  (void)scene;
}

void QtSceneDrawer::initBuffers() { makeCurrent(); }

void QtSceneDrawer::destroyBuffers() {
  makeCurrent();

  if (vao_->isCreated()) {
    vao_->destroy();
  }

  if (vbo_->isCreated()) {
    vbo_->destroy();
  }

  if (ebo_->isCreated()) {
    ebo_->destroy();
  }
}

void QtSceneDrawer::setToIdentity() {
  rotate_->setToIdentity();
  scale_->setToIdentity();
  move_->setToIdentity();
}

void QtSceneDrawer::afinneGPU(const Data *data) {
  setToIdentity();

  rotate_->rotate(data->rotate_x, 1, 0, 0);
  rotate_->rotate(data->rotate_y, 0, 1, 0);
  rotate_->rotate(data->rotate_z, 0, 0, 1);
  scale_->scale(data->scale, data->scale, data->scale);
  move_->translate(data->move_x, data->move_y, data->move_z);
}

const char *QtSceneDrawer::kVertexShader =
    "attribute vec4 vertex;\n"
    "uniform mat4 coeffMatrix;\n"
    "void main() {\n"
    "  gl_Position = coeffMatrix * vertex;\n"
    "}\n";

const char *QtSceneDrawer::kFragmentShader =
    "uniform vec4 color;\n"
    "void main() {\n"
    "  gl_FragColor = color;\n"
    "}\n";

}  // namespace s21
