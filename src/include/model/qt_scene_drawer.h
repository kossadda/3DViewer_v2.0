/**
 * @file open_gl.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_QT_SCENE_DRAWER_H_
#define SRC_INCLUDE_MODEL_QT_SCENE_DRAWER_H_

#include <QGridLayout>
#include <QMouseEvent>

#include "include/controller/data.h"
#include "include/model/open_gl.h"
#include "include/model/scene.h"
#include "include/model/scene_drawer_base.h"

namespace s21 {

class QtSceneDrawer : public SceneDrawerBase {
 public:
  QtSceneDrawer();
  ~QtSceneDrawer();

  void drawScene(Scene *scene) override;
  void clearScene() override;

 private slots:
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void wheelEvent(QWheelEvent *event);

 private:
  OpenGL *gl;
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_QT_SCENE_DRAWER_H_
