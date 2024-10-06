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

#include "include/view/afinne_data.h"
#include "include/view/object_data.h"
#include "include/view/object_scene.h"
#include "include/view/path_reader.h"
#include "include/view/scene_data.h"
#include "include/view/style.h"

class MainWindow : public QWidget {
 public:
  MainWindow();

 private:
  void allocateMemory();
  void initView();

  QGridLayout *left_menu;
  PathReader *path_;
  ObjectScene *scene_;
  AfinneData *rotate_;
  AfinneData *scale_;
  AfinneData *translate_;
  ObjectData *figure_;
  SceneData *setting_;
};

#endif  // SRC_INCLUDE_VIEW_MAIN_WINDOW_H_
