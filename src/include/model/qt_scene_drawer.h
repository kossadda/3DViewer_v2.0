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

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>

#include "include/controller/data.h"
#include "include/model/scene_drawer_base.h"

namespace s21 {

class QtSceneDrawer : public SceneDrawerBase,
                      public QOpenGLWidget,
                      public QOpenGLFunctions {
 public:
  QtSceneDrawer();
  ~QtSceneDrawer();

  void drawScene(const Scene &scene) override;

 private:
  void allocateMemory();
  void initializeGL() override;
  void setToIdentity();
  void afinneGPU(const Data *data);
  void initObject(const Scene &scene);
  void destroyBuffers();
  void initBuffers();

  static const char *kVertexShader;
  static const char *kFragmentShader;

  QOpenGLShaderProgram *program_;
  QOpenGLBuffer *vbo_;
  QOpenGLBuffer *ebo_;
  QOpenGLVertexArrayObject *vao_;

  QMatrix4x4 *rotate_;
  QMatrix4x4 *scale_;
  QMatrix4x4 *move_;
  QMatrix4x4 *projection_;
  QMatrix4x4 *camera_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_QT_SCENE_DRAWER_H_
