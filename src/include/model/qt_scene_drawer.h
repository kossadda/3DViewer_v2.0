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

#include <QButtonGroup>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>

#include "include/controller/data.h"

namespace s21 {

class Point3D {
 public:
  Point3D(float x, float y, float z) : x(x), y(y), z(z) {}
  float *base() { return &x; }

 private:
  float x, y, z;
};

class Edge {
 public:
  Edge(int begin, int end) : begin_(begin), end_(end) {}
  int *base() { return &begin_; }

 private:
  int begin_;
  int end_;
};

class Scene {
 public:
  Scene() = default;
  Scene(const std::vector<Point3D> &vertices, const std::vector<Edge> &edges)
      : vertices_(vertices), edges_(edges) {}

  const std::vector<Point3D> &vertices() const noexcept { return vertices_; }
  const std::vector<Edge> &edges() const noexcept { return edges_; }

 private:
  std::vector<Point3D> vertices_;
  std::vector<Edge> edges_;
};

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
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;

 private:
  void initBuffers();
  void destroyBuffers();
  void setupProjection(int w, int h);
  void afinneCPU();
  void afinneGPU();
  void setAllMatrixToIdentity();
  Scene *testModel();

  static const char *kVertexShader;
  static const char *kFragmentShader;

  Data &data_;
  Scene *scene_;

  int coeff_matrix_;
  int color_;

  QOpenGLShaderProgram *program_;
  QOpenGLBuffer vbo_;
  QOpenGLBuffer ebo_;
  QOpenGLVertexArrayObject vao_;

  QMatrix4x4 projection_;
  QMatrix4x4 camera_;
  QMatrix4x4 rotate_;
  QMatrix4x4 move_;
  QMatrix4x4 scale_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_QT_SCENE_DRAWER_H_
