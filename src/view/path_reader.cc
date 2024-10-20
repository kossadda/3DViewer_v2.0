/**
 * @file path_reader.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief Implementation of the PathReader class
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/path_reader.h"

namespace s21 {

/**
 * @brief Constructs the PathReader object and initializes the UI components.
 */
PathReader::PathReader() : BaseWidget{} {
  allocateMemory();
  initView();
}

/**
 * @brief Allocates memory for the necessary UI elements (buttons, text fields,
 * labels, and file dialog).
 */
void PathReader::allocateMemory() {
  path_button_ = new QPushButton{"Load"};
  path_edit_ = new QLineEdit;
  vertex_info_ = new QLabel{"Vertex: 0"};
  edge_info_ = new QLabel{"Facets: 0"};
  dialog_ = new QFileDialog{this, "Choose wireframe file", QDir::homePath(),
                            "Wireframe obj (*.obj)"};
}

/**
 * @brief Sets up the layout and applies styles to the UI components. Connects
 * UI events to their handlers.
 */
void PathReader::initView() {
  grid_->setHorizontalSpacing(15);

  grid_->addWidget(path_button_, 0, 0, 2, 1);
  grid_->addWidget(path_edit_, 0, 1, 2, 1);
  grid_->addWidget(vertex_info_, 0, 2, 1, 1);
  grid_->addWidget(edge_info_, 1, 2, 1, 1);

  path_button_->setFixedSize(70, 40);
  path_edit_->setFixedHeight(40);
  vertex_info_->setMaximumWidth(250);
  edge_info_->setMaximumWidth(250);

  vertex_info_->setAlignment(Qt::AlignRight);
  edge_info_->setAlignment(Qt::AlignRight);

  path_button_->setStyleSheet(Style::kButtonStyle);
  path_edit_->setStyleSheet(Style::kLineEditStyle);
  vertex_info_->setStyleSheet(Style::kLabelStyle);
  edge_info_->setStyleSheet(Style::kLabelStyle);
  dialog_->setStyleSheet(Style::kFileDialogStyle);

  connect(path_button_, &QPushButton::clicked, this,
          &PathReader::onButtonClicked);
  connect(path_edit_, &QLineEdit::returnPressed, this, &PathReader::validPath);
}

/**
 * @brief Opens a file dialog for selecting a wireframe file when the button is
 * clicked.
 */
void PathReader::onButtonClicked() {
  if (dialog_->exec() == QDialog::Accepted) {
    path_edit_->setText(dialog_->selectedFiles().first());
    validPath();
  }
}

/**
 * @brief Validates the entered file path, ensuring it is correct and exists.
 * Emits a signal if valid.
 */
void PathReader::validPath() {
  QFileInfo info{path_edit_->text()};
  bool valid_path{true};
  QString error_message;

  if (!info.isAbsolute()) {
    valid_path = false;
    error_message = "Enter the absolute path to the file";
  } else if (!info.exists()) {
    valid_path = false;
    error_message = "File " + info.fileName() + " does not exist";
  } else if (info.suffix() != "obj") {
    valid_path = false;
    error_message = "Enter path to wireframe file (.obj)";
  }

  if (!valid_path) {
    QMessageBox::warning(this, "Error", error_message);
  } else {
    emit valid(path_edit_->text());
  }
}

/**
 * @brief Updates the UI labels with the provided vertex and edge counts.
 * @param vertex_count The number of vertices.
 * @param edge_count The number of edges.
 */
void PathReader::setInfo(int vertex_count, int edge_count) {
  vertex_info_->setText("Vertex: " + QString::number(vertex_count));
  edge_info_->setText("Edge: " + QString::number(edge_count));
}

/**
 * @brief Stores the selected file path for future use.
 */
void PathReader::recordData() {
  Data::data().path = path_edit_->text().toStdString();
}

}  // namespace s21
