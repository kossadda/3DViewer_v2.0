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

#ifndef SRC_INCLUDE_VIEW_OBJECT_SCENE_H
#define SRC_INCLUDE_VIEW_OBJECT_SCENE_H

#include <QWidget>
#include <QOpenGLWidget>

class ObjectScene : QWidget {
 public:
  ObjectScene();
  ~ObjectScene();

 private:
  void allocateMemory();
  void initView();

  QOpenGLWidget *scene_{};
};

#endif  // SRC_INCLUDE_VIEW_OBJECT_SCENE_H