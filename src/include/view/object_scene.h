/**
 * @file object_scene.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_OBJECT_SCENE_H_
#define SRC_INCLUDE_VIEW_OBJECT_SCENE_H_

#include <QOpenGLWidget>

#include "include/view/base_widget.h"

class ObjectScene : public BaseWidget {
 public:
  ObjectScene();

  void drawScene(const QString& path);

 private:
  void allocateMemory();
  void initView();

  QOpenGLWidget *scene_{};
};

#endif  // SRC_INCLUDE_VIEW_OBJECT_SCENE_H_
