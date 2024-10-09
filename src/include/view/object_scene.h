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

#include "include/controller/data.h"
#include "include/model/qt_scene_drawer.h"
#include "include/view/base_widget.h"

namespace s21 {

class ObjectScene : public BaseWidget {
  Q_OBJECT

 public:
  ObjectScene();

  // void drawScene(const QString &path);
  void drawScene();  // drawScene without path is temporary
  void imageSave(const QString &path, const QString &format);
  void gifSave(const QString &path);
  void clearScene();

 private:
  void allocateMemory();
  void initView();

  QtSceneDrawer *scene_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_OBJECT_SCENE_H_
