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
  right_menu = new QGridLayout;
  path_ = new PathReader;
  scene_ = new ObjectScene;
  rotate_ = new AfinneData{new QLabel{"Rotate"}, {"X", "Y", "Z"}, -360, 360};
  scale_ = new AfinneData{new QLabel{"Scale"}, {""}, 1, 600, 100};
  translate_ =
      new AfinneData{new QLabel{"Translate"}, {"X", "Y", "Z"}, -100, 100};
  vertex_ = new FigureData{new QLabel{"Vertex"}, {"□", "○", "none"}};
  lines_ = new FigureData{new QLabel{"Facet"}, {"──", "----", "none"}};
  setting_ = new SceneSetting{new QLabel{"Settings"}};
}

void MainWindow::initView() {
  QGridLayout *grid{new QGridLayout};
  setLayout(grid);
  setStyleSheet(Style::kWindowStyle);

  left_menu->addWidget(rotate_);
  left_menu->addWidget(scale_);
  left_menu->addWidget(translate_);
  right_menu->addWidget(vertex_);
  right_menu->addWidget(lines_);
  right_menu->addWidget(setting_);
  grid->addLayout(left_menu, 1, 0, Qt::AlignTop);
  grid->addWidget(path_, 0, 1);
  grid->addWidget(scene_, 1, 1);
  grid->addLayout(right_menu, 1, 2, Qt::AlignTop);

  rotate_->setFixedSize(340, 200);
  translate_->setFixedSize(340, 200);
  scale_->setFixedSize(340, 100);
  path_->setFixedHeight(60);
  vertex_->setFixedSize(230, 190);
  lines_->setFixedSize(230, 190);
  setting_->setFixedSize(230, 190);
}
