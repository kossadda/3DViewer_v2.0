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

namespace s21 {

MainWindow::MainWindow() : QWidget{} {
  allocateMemory();
  initView();
}

void MainWindow::allocateMemory() {
  left_menu = new QGridLayout;
  path_ = new PathReader;
  scene_ = new SceneView;
  rotate_ = new AfinneData{new QLabel{"Rotate"}, {"X", "Y", "Z"}, -360, 360};
  scale_ = new AfinneData{new QLabel{"Scale"}, {"%"}, 1, 600};
  move_ = new AfinneData{new QLabel{"Translate"}, {"X", "Y", "Z"}, -100, 100};
  figure_ = new ObjectData;
  setting_ = new SceneData{new QLabel{"Scene"}};
  function_ = new Function;
}

void MainWindow::initView() {
  QGridLayout *grid{new QGridLayout};
  setLayout(grid);
  setStyleSheet(Style::kWindowStyle);
  setWindowIcon(QIcon{":main"});
  setWindowTitle("3DViewer");
  std::setlocale(LC_NUMERIC, "C");

  left_menu->addWidget(rotate_);
  left_menu->addWidget(scale_);
  left_menu->addWidget(move_);
  left_menu->addWidget(figure_);
  left_menu->addWidget(setting_);
  grid->addLayout(left_menu, 0, 0, 2, 1, Qt::AlignTop);
  grid->addWidget(path_, 0, 1);
  grid->addWidget(scene_, 1, 1, 3, 1);
  grid->addWidget(function_, 2, 0, 2, 1, Qt::AlignBottom);

  rotate_->setFixedSize(310, 170);
  move_->setFixedSize(310, 170);
  scale_->setFixedSize(310, 90);
  path_->setFixedHeight(60);
  setting_->setFixedSize(310, 190);
  figure_->setFixedSize(310, 190);

  connect(scene_, &SceneView::mouseEvent, rotate_, &AfinneData::setData);
  connect(scene_, &SceneView::mouseEvent, scale_, &AfinneData::setData);
  connect(scene_, &SceneView::mouseEvent, move_, &AfinneData::setData);
  connect(rotate_, &AfinneData::dataChanged, this, &MainWindow::recordData);
  connect(scale_, &AfinneData::dataChanged, this, &MainWindow::recordData);
  connect(move_, &AfinneData::dataChanged, this, &MainWindow::recordData);
  connect(figure_, &ObjectData::dataChanged, this, &MainWindow::recordData);
  connect(setting_, &SceneData::dataChanged, this, &MainWindow::recordData);
  connect(path_, &PathReader::valid, scene_, &SceneView::loadScene);
  connect(path_, &PathReader::valid, this, &MainWindow::resetData);
  connect(scene_, &SceneView::drawInfo, path_, &PathReader::setInfo);
  connect(function_, &Function::imageSave, scene_, &SceneView::imageSave);
  connect(function_, &Function::gifSave, scene_, &SceneView::gifSave);
  connect(function_, &Function::clear, scene_, &SceneView::clearScene);
  connect(function_, &Function::reset, this, &MainWindow::resetData);
}

void MainWindow::recordData() {
  rotate_->recordData();
  scale_->recordData();
  move_->recordData();
  setting_->recordData();
  figure_->recordData();
  path_->recordData();

  scene_->drawScene();
}

void MainWindow::resetData() {
  rotate_->reset();
  scale_->reset();
  move_->reset();

  scene_->drawScene();
}

}  // namespace s21
