/**
 * @file open_gl.h
 * @author kossadda (https://github.com/kossadda)
 * @brief OpenGL widget for rendering 3D scenes and managing OpenGL buffers
 * @version 1.0
 * @date 2024-10-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_OPEN_GL_H_
#define SRC_INCLUDE_MODEL_OPEN_GL_H_

#include <QDir>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>
#include <QTimer>
#include <string>

#include "include/controller/data.h"
#include "include/model/scene.h"
#include "include/model/transform_matrix_builder.h"

namespace s21 {

/**
 * @class OpenGL
 * @brief A widget for rendering 3D scenes using OpenGL.
 *
 * The `OpenGL` class provides functionality for rendering 3D scenes within a
 * Qt widget using OpenGL. It manages OpenGL buffers, shaders, and handles user
 * input events such as mouse movement and wheel events. The class also supports
 * saving rendered scenes as images and GIFs.
 */
class OpenGL : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT

 public:
  OpenGL();
  ~OpenGL();

  bool isBufferAllocate() const;
  void initBuffers(Scene *scene);
  void updateBuffer(Scene *scene);
  void destroyBuffers();
  void createImage(const std::string &path, const std::string &format);
  void createGif(const std::string &path);

 signals:
  void mousePress(QMouseEvent *event);
  void mouseMove(QMouseEvent *event);
  void mouseWheel(QWheelEvent *event);
  void recorded();

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
  TransformMatrix afinneCPU() const;
  QMatrix4x4 afinneGPU() const;
  void createSnapshot();
  void snapshotsToGif() const;

  static const char *kVertexShader;
  static const char *kFragmentShader;
  static constexpr float kMoveScale{50.f};
  static constexpr int kGifFPS{10};
  static constexpr int kGifLength{5};

  Data &data_{Data::data()};
  int coeff_matrix_;
  int color_;
  int vbo_size_{};
  int ebo_size_{};

  QOpenGLShaderProgram *program_;
  QOpenGLBuffer *vbo_;
  QOpenGLBuffer *ebo_;
  QOpenGLVertexArrayObject *vao_;

  QMatrix4x4 projection_;
  QMatrix4x4 camera_;

  QString abs_dir_;
  QTimer *periodic_;
  std::string path_;
  int snapshot_count_{};
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_OPEN_GL_H_
