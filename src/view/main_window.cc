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
  rotate_ = new AfinneData{new QLabel{"Rotate"}, {"X", "Y", "Z"}, -360, 360};
  scale_ = new AfinneData{new QLabel{"Scale"}, {""}, -99, 600};
  translate_ =
      new AfinneData{new QLabel{"Translate"}, {"X", "Y", "Z"}, -100, 100};
  vertex_ = new FigureData;
  lines_ = new FigureData;
  setting_ = new SceneSetting;
}

void MainWindow::initView() {
  QGridLayout *grid{new QGridLayout};

  setLayout(grid);
  setStyleSheet(Style::kWindowStyle);

  grid->addWidget(rotate_, 0, 0);
  grid->addWidget(scale_, 1, 0);
  grid->addWidget(translate_, 2, 0);
  grid->addWidget(scene_, 0, 1, 3, 1);
  // grid->addWidget(path_);
  // grid->addWidget(vertex_);
  // grid->addWidget(lines_);
  // grid->addWidget(setting_);


  rotate_->setFixedSize(350, 200);
  translate_->setFixedSize(350, 200);
  scale_->setFixedSize(350, 100);
}
