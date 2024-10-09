/**
 * @file qt_scene_drawer.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_QT_SCENE_DRAWER_H_
#define SRC_INCLUDE_MODEL_QT_SCENE_DRAWER_H_

#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>

#include "include/controller/data.h"
#include "include/model/scene.h"
#include "include/model/transform_matrix_builder.h"

namespace s21 {

class QtSceneDrawer : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT

 public:
  QtSceneDrawer();
  ~QtSceneDrawer();

  void initModel(Scene *scene);

 signals:
  void mousePress(QMouseEvent *event);
  void mouseMove(QMouseEvent *event);
  void mouseWheel(QWheelEvent *event);

 protected:
  // void initializeGL() override;
  // void paintGL() override;
  // void resizeGL(int w, int h) override;
  // void mousePressEvent(QMouseEvent *event) override;
  // void mouseMoveEvent(QMouseEvent *event) override;
  // void wheelEvent(QWheelEvent *event) override;

 private:
  void allocateMemory();
  void setupProjection(int w, int h);
  void initBuffers();
  void updateBuffer(const TransformMatrix &matrix);
  void destroyBuffers();
  TransformMatrix afinneCPU();
  QMatrix4x4 afinneGPU();
  Scene *testModel();  // temp

  static const char *kVertexShader;
  static const char *kFragmentShader;

  Data &data_{Data::data()};
  Scene *scene_;

  int coeff_matrix_;
  int color_;

  QOpenGLShaderProgram *program_;
  QOpenGLBuffer *vbo_;
  QOpenGLBuffer *ebo_;
  QOpenGLVertexArrayObject *vao_;

  QMatrix4x4 projection_;
  QMatrix4x4 camera_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_QT_SCENE_DRAWER_H_
