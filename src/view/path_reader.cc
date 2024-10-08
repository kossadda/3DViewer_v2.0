/**
 * @file path_reader.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/path_reader.h"

namespace s21 {

PathReader::PathReader() : BaseWidget{} {
  allocateMemory();
  initView();
}

void PathReader::allocateMemory() {
  path_button_ = new QPushButton{"Load"};
  path_edit_ = new QLineEdit;
  vertex_info_ = new QLabel{"Vertex: 0"};
  facet_info_ = new QLabel{"Facets: 0"};
  dialog_ = new QFileDialog{this, "Choose wireframe file", QDir::homePath(),
                            "Wireframe obj (*.obj)"};
}

void PathReader::initView() {
  grid_->setHorizontalSpacing(15);

  grid_->addWidget(path_button_, 0, 0, 2, 1);
  grid_->addWidget(path_edit_, 0, 1, 2, 1);
  grid_->addWidget(vertex_info_, 0, 2, 1, 1);
  grid_->addWidget(facet_info_, 1, 2, 1, 1);

  path_button_->setFixedSize(70, 40);
  path_edit_->setFixedHeight(40);
  vertex_info_->setMaximumWidth(250);
  facet_info_->setMaximumWidth(250);

  vertex_info_->setAlignment(Qt::AlignRight);
  facet_info_->setAlignment(Qt::AlignRight);

  path_button_->setStyleSheet(Style::kButtonStyle);
  path_edit_->setStyleSheet(Style::kLineEditStyle);
  vertex_info_->setStyleSheet(Style::kLabelStyle);
  facet_info_->setStyleSheet(Style::kLabelStyle);
  dialog_->setStyleSheet(Style::kFileDialogStyle);

  connect(path_button_, &QPushButton::clicked, this,
          &PathReader::onButtonClicked);
  connect(path_edit_, &QLineEdit::returnPressed, this, &PathReader::validPath);
}

void PathReader::onButtonClicked() {
  if (dialog_->exec() == QDialog::Accepted) {
    path_edit_->setText(dialog_->selectedFiles().first());
    validPath();
  }
}

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

void PathReader::setInfo(int vertex_count, int facet_count) {
  vertex_info_->setText("Vertex: " + QString::number(vertex_count));
  facet_info_->setText("Facet: " + QString::number(facet_count));
}

void PathReader::recordData() {
  Data::data().path = path_edit_->text().toStdString();
}

}  // namespace s21
