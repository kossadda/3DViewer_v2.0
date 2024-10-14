/**
 * @file open_gl.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_OPEN_GL_H_
#define SRC_INCLUDE_MODEL_OPEN_GL_H_

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

class OpenGL : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT

 public:
  OpenGL();
  ~OpenGL();

  bool isBufferAllocate();
  void initBuffers(Scene *scene);
  void updateBuffer(Scene *scene);
  void destroyBuffers();

 signals:
  void mousePress(QMouseEvent *event);
  void mouseMove(QMouseEvent *event);
  void mouseWheel(QWheelEvent *event);

 protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;

 private:
  void allocateMemory();
  void setupProjection(int w, int h);
  TransformMatrix afinneCPU();
  QMatrix4x4 afinneGPU();

  static const char *kVertexShader;
  static const char *kFragmentShader;

  Data &data_{Data::data()};

  int coeff_matrix_;
  int color_;

  int vbo_size_;
  int ebo_size_;

  QOpenGLShaderProgram *program_;
  QOpenGLBuffer *vbo_;
  QOpenGLBuffer *ebo_;
  QOpenGLVertexArrayObject *vao_;

  QMatrix4x4 projection_;
  QMatrix4x4 camera_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_OPEN_GL_H_
