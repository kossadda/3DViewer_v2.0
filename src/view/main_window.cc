/**
 * @file main_window.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/main_window.h"

MainWindow::MainWindow() : QWidget{} {
  allocateMemory();
  initView();
}

MainWindow::~MainWindow() {
  delete path_;
  delete scene_;
  delete rotate_;
  delete scale_;
  delete translate_;
  delete vertex_;
  delete lines_;
  delete setting_;
}

void MainWindow::allocateMemory() {
  path_ = new PathReader;
  scene_ = new ObjectScene;
  rotate_ = new AfinneData;
  scale_ = new AfinneData;
  translate_ = new AfinneData;
  vertex_ = new FigureData;
  lines_ = new FigureData;
  setting_ = new SceneSetting;
}

void MainWindow::initView() {}
