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

void MainWindow::allocateMemory() {
  left_menu = new QGridLayout;
  path_ = new PathReader;
  scene_ = new ObjectScene;
  rotate_ = new AfinneData{new QLabel{"Rotate"}, {"X", "Y", "Z"}, -360, 360};
  scale_ = new AfinneData{new QLabel{"Scale"}, {""}, 1, 600, 100};
  translate_ =
      new AfinneData{new QLabel{"Translate"}, {"X", "Y", "Z"}, -100, 100};
  figure_ = new FigureData;
  setting_ = new SceneSetting{new QLabel{"Settings"}};
}

void MainWindow::initView() {
  QGridLayout *grid{new QGridLayout};
  setLayout(grid);
  setStyleSheet(Style::kWindowStyle);

  left_menu->addWidget(rotate_);
  left_menu->addWidget(scale_);
  left_menu->addWidget(translate_);
  left_menu->addWidget(figure_);
  grid->addLayout(left_menu, 0, 0, 2, 1, Qt::AlignTop);
  grid->addWidget(path_, 0, 1);
  grid->addWidget(scene_, 1, 1);

  rotate_->setFixedSize(320, 170);
  translate_->setFixedSize(320, 170);
  scale_->setFixedSize(320, 100);
  path_->setFixedHeight(60);
  figure_->setFixedSize(320, 170);
  setting_->setFixedSize(230, 190);
}
