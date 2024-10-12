/**
 * @file main_window.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_MAIN_WINDOW_H_
#define SRC_INCLUDE_VIEW_MAIN_WINDOW_H_

#include <QGridLayout>
#include <QWidget>

#include "include/controller/data.h"
#include "include/view/afinne_data.h"
#include "include/view/function.h"
#include "include/view/object_data.h"
#include "include/view/scene_view.h"
#include "include/view/path_reader.h"
#include "include/view/scene_data.h"
#include "include/view/style.h"

namespace s21 {

class MainWindow : public QWidget {
  Q_OBJECT

 public:
  MainWindow();
  void resetData();

 private:
  void allocateMemory();
  void initView();
  void recordData();

  QGridLayout *left_menu;
  PathReader *path_;
  SceneView *scene_;
  AfinneData *rotate_;
  AfinneData *scale_;
  AfinneData *move_;
  ObjectData *figure_;
  SceneData *setting_;
  Function *function_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_MAIN_WINDOW_H_
