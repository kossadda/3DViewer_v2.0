/**
 * @file scene_drawer_base.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_SCENE_DRAWER_BASE_H_
#define SRC_INCLUDE_MODEL_SCENE_DRAWER_BASE_H_

#include <QMouseEvent>
#include <QWidget>

#include "include/model/scene.h"

namespace s21 {

class SceneDrawerBase : public QWidget {
  Q_OBJECT

 public:
  virtual ~SceneDrawerBase() = default;
  virtual void drawScene(Scene *scene) = 0;
  virtual void clearScene() = 0;

 signals:
  void mousePress(QMouseEvent *event);
  void mouseMove(QMouseEvent *event);
  void mouseWheel(QWheelEvent *event);
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_SCENE_DRAWER_BASE_H_
