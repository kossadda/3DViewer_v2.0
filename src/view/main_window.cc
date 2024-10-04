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
}

void MainWindow::allocateMemory() {
  path_ = new PathReader;
}

void MainWindow::initView() {}