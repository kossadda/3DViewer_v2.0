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

#include <QWidget>
#include <QGridLayout>

#include "include/view/object_scene.h"
#include "include/view/path_reader.h"
#include "include/view/afinne_data.h"
#include "include/view/figure_data.h"
#include "include/view/scene_setting.h"

class MainWindow : public QWidget {
 public:
  MainWindow();
  ~MainWindow();

 private:
  void allocateMemory();
  void initView();

  PathReader *path_;
  ObjectScene *scene_;
  AfinneData *rotate_;
  AfinneData *scale_;
  AfinneData *translate_;
  FigureData *vertex_;
  FigureData *lines_;
  SceneSetting *setting_;
};

#endif  // SRC_INCLUDE_VIEW_MAIN_WINDOW_H_
