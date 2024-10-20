/**
 * @file scene_view.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file that declares the SceneView class for managing 3D scene
 * rendering and user interaction
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_SCENE_VIEW_H_
#define SRC_INCLUDE_VIEW_SCENE_VIEW_H_

#include <QMessageBox>
#include <QPoint>

#include "include/controller/data.h"
#include "include/controller/facade.h"
#include "include/view/base_widget.h"

namespace s21 {

/**
 * @class SceneView
 * @brief A class for rendering and managing interactions with a 3D scene.
 *
 */
class SceneView : public BaseWidget {
  Q_OBJECT

 public:
  SceneView();
  ~SceneView();

  void loadScene(const QString &path);
  void drawScene();
  void imageSave(const QString &path, const QString &format);
  void gifSave(const QString &path);

 signals:
  void mouseEvent();
  void drawInfo(int vertex_count, int edge_count);
  void recorded();

 private slots:
  void onMousePress(QMouseEvent *event);
  void onMouseMove(QMouseEvent *event);
  void onMouseWheel(QWheelEvent *event);
  void onRecorded();

 private:
  void allocateMemory();
  void initView();
  template <typename View>
  void connectSignals(View *view);

  Data &data_{Data::data()};

  bool leftMouse;
  bool rightMouse;
  QPoint startPos;

  Facade *controller_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_SCENE_VIEW_H_
