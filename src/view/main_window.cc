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
  loadSettings();
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
  QGridLayout* grid{new QGridLayout};
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
  connect(scene_, &SceneView::drawInfo, path_, &PathReader::setInfo);
  connect(scene_, &SceneView::recorded, function_, &Function::changeStatus);
  connect(rotate_, &AfinneData::dataChanged, this, &MainWindow::recordData);
  connect(scale_, &AfinneData::dataChanged, this, &MainWindow::recordData);
  connect(move_, &AfinneData::dataChanged, this, &MainWindow::recordData);
  connect(figure_, &ObjectData::dataChanged, this, &MainWindow::recordData);
  connect(setting_, &SceneData::dataChanged, this, &MainWindow::recordData);
  connect(path_, &PathReader::valid, scene_, &SceneView::loadScene);
  connect(path_, &PathReader::valid, this, &MainWindow::resetData);
  connect(function_, &Function::imageSave, scene_, &SceneView::imageSave);
  connect(function_, &Function::gifSave, scene_, &SceneView::gifSave);
  connect(function_, &Function::clear, this, &MainWindow::resetAll);
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

void MainWindow::resetAll() {
  rotate_->reset();
  scale_->reset();
  move_->reset();
  setting_->reset();
  figure_->reset();

  scene_->drawScene();
}

void MainWindow::closeEvent(QCloseEvent* event) {
  saveSettings();
  QWidget::closeEvent(event);
}

void MainWindow::saveSettings() {
  QSettings settings("3DViewer", "3DViewerApp");

  settings.setValue("geometry", saveGeometry());
  settings.setValue("background_color", data_.background_color);
  settings.setValue("vertex_color", data_.vertex_color);
  settings.setValue("facet_color", data_.facet_color);
  settings.setValue("vertex_size", data_.vertex_size);
  settings.setValue("facet_size", data_.facet_size);
  settings.setValue("vertex_type", static_cast<int>(data_.vertex_type));
  settings.setValue("facet_type", static_cast<int>(data_.facet_type));
  settings.setValue("calculate_type", static_cast<int>(data_.calculate_type));
  settings.setValue("projection_type", static_cast<int>(data_.projection_type));
  settings.setValue("file_path", QString::fromStdString(data_.path));
}

void MainWindow::loadSettings() {
  QSettings settings("3DViewer", "3DViewerApp");

  if (settings.contains("geometry")) {
    restoreGeometry(settings.value("geometry").toByteArray());
    data_.background_color = settings.value("background_color").value<QColor>();
    data_.vertex_color = settings.value("vertex_color").value<QColor>();
    data_.facet_color = settings.value("facet_color").value<QColor>();
    data_.vertex_size = settings.value("vertex_size").value<int>();
    data_.facet_size = settings.value("facet_size").value<int>();
    data_.vertex_type =
        static_cast<VertexType>(settings.value("vertex_type").value<int>());
    data_.facet_type =
        static_cast<FacetType>(settings.value("facet_type").value<int>());
    data_.calculate_type = static_cast<CalculateType>(
        settings.value("calculate_type").value<int>());
    data_.projection_type = static_cast<ProjectionType>(
        settings.value("projection_type").value<int>());
    data_.path = settings.value("file_path").value<QString>().toStdString();
  }
}

}  // namespace s21
