/**
 * @file scene_drawer.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for the SceneDrawer class
 * @version 1.0
 * @date 2024-10-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_SCENE_DRAWER_H_
#define SRC_INCLUDE_MODEL_SCENE_DRAWER_H_

#include <QGridLayout>
#include <QMouseEvent>
#include <string>

#include "include/controller/data.h"
#include "include/model/open_gl.h"
#include "include/model/scene.h"
#include "include/model/scene_drawer_base.h"

namespace s21 {

/**
 * @class SceneDrawer
 * @brief A class for drawing 3D scenes and handling user interactions.
 *
 * SceneDrawer is responsible for rendering 3D scenes using OpenGL, responding
 * to mouse events for interaction, and providing functionality to save rendered
 * images and GIFs.
 */
class SceneDrawer : public SceneDrawerBase {
 public:
  SceneDrawer();
  ~SceneDrawer();

  void drawScene(Scene *scene) override;
  void saveImage(const std::string &path, const std::string format) override;
  void saveGif(const std::string &path) override;
  void clearScene() override;

 private slots:
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void wheelEvent(QWheelEvent *event);
  void onRecorded();

 private:
  OpenGL *gl_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_SCENE_DRAWER_H_
