/**
 * @file main_window.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief Implementation of the MainWindow class
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/main_window.h"

namespace s21 {

/**
 * @brief Construct a new MainWindow object.
 */
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

/**
 * @brief Initializes the user interface components.
 *
 * This method sets up the layout and initializes the various UI elements
 * within the MainWindow.
 */
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

/**
 * @brief Records the current data settings.
 *
 * This method saves the current state of data for future retrieval.
 */
void MainWindow::recordData() {
  rotate_->recordData();
  scale_->recordData();
  move_->recordData();
  setting_->recordData();
  figure_->recordData();
  path_->recordData();

  scene_->drawScene();
}

/**
 * @brief Resets the data in the application.
 *
 * This method clears the current data and restores default values.
 */
void MainWindow::resetData() {
  rotate_->reset();
  scale_->reset();
  move_->reset();

  scene_->drawScene();
}

/**
 * @brief Resets all components of the application.
 *
 * This method resets the application state to its initial configuration,
 * including UI elements and internal data.
 */

void MainWindow::resetAll() {
  rotate_->reset();
  scale_->reset();
  move_->reset();
  setting_->reset();
  figure_->reset();

  scene_->drawScene();
}

/**
 * @brief Override for the close event.
 *
 * This method is called when the main window is requested to close.
 * It allows for cleanup operations before the window is closed.
 *
 * @param event The close event.
 */
void MainWindow::closeEvent(QCloseEvent* event) {
  saveSettings();
  QWidget::closeEvent(event);
}

/**
 * @brief Saves user settings to persistent storage.
 *
 * This method stores the current application settings using QSettings.
 */
void MainWindow::saveSettings() const {
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

/**
 * @brief Loads user settings from persistent storage.
 *
 * This method retrieves and applies stored settings from QSettings.
 */
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
