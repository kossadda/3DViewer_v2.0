/**
 * @file scene_drawer_base.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for the abstract base class SceneDrawerBase
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
#include <string>

#include "include/model/scene.h"

namespace s21 {

/**
 * @class SceneDrawerBase
 * @brief An abstract base class for 3D scene rendering and interaction.
 *
 * SceneDrawerBase provides an interface for rendering a 3D scene,
 * clearing the scene, and saving the rendered scene as images or GIFs. It
 * also includes signals for handling user interactions via mouse events.
 */
class SceneDrawerBase : public QWidget {
  Q_OBJECT

 public:
  virtual ~SceneDrawerBase() = default;
  virtual void drawScene(Scene *scene) = 0;
  virtual void clearScene() = 0;
  virtual void saveImage(const std::string &path, const std::string format) = 0;
  virtual void saveGif(const std::string &path) = 0;

 signals:
  void mousePress(QMouseEvent *event);
  void mouseMove(QMouseEvent *event);
  void mouseWheel(QWheelEvent *event);
  void recorded();
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_SCENE_DRAWER_BASE_H_
