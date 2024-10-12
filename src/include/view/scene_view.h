/**
 * @file scene_view.h
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

#include <QPoint>

#include "include/controller/data.h"
#include "include/controller/facade.h"
#include "include/view/base_widget.h"

namespace s21 {

class SceneView : public BaseWidget {
  Q_OBJECT

 public:
  SceneView();
  ~SceneView();

  void loadScene(const QString &path);
  void drawScene();
  void imageSave(const QString &path, const QString &format);
  void gifSave(const QString &path);
  void clearScene();

 signals:
  void mouseEvent();

 private slots:
  void onMousePress(QMouseEvent *event);
  void onMouseMove(QMouseEvent *event);
  void onMouseWheel(QWheelEvent *event);

 private:
  void allocateMemory();
  void initView();

  Data &data_{Data::data()};

  bool leftMouse;
  bool rightMouse;
  QPoint startPos;

  Facade *controller_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_OBJECT_SCENE_H_
