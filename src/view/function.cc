/**
 * @file function.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/function.h"

Function::Function() : QWidget{} {
  allocateMemory();
  initView();
}

void Function::allocateMemory() {
  grid_ = new QGridLayout;
  save_img_ = new QPushButton{"Save image"};
  save_gif_ = new QPushButton{"Save gif"};
  clear_ = new QPushButton{"Clear scene"};
  reset_ = new QPushButton{"Reset"};
  img_dialog_ = new QFileDialog(this, "Save image as", QDir::homePath());
  gif_dialog_ = new QFileDialog(this, "Save gif as", QDir::homePath());
}

void Function::initView() {
  QVector<QPushButton *> buttons{save_img_, save_gif_, clear_, reset_};

  setLayout(grid_);
  grid_->addWidget(save_img_, 0, 0);
  grid_->addWidget(save_gif_, 0, 1);
  grid_->addWidget(clear_, 1, 0);
  grid_->addWidget(reset_, 1, 1);

  for (auto button : buttons) {
    button->setStyleSheet(Style::kButtonStyle);
    button->setFixedHeight(50);
  }

  img_dialog_->setAcceptMode(QFileDialog::AcceptSave);
  gif_dialog_->setAcceptMode(QFileDialog::AcceptSave);

  img_dialog_->setNameFilters({"BMP files (*.bmp)", "JPEG files (*.jpeg)"});
  gif_dialog_->setNameFilter("GIF files (*.gif)");

  img_dialog_->setStyleSheet(Style::kFileDialogStyle);
  gif_dialog_->setStyleSheet(Style::kFileDialogStyle);

  connect(save_img_, &QPushButton::clicked, this,
          &Function::onImageSaveClicked);
  connect(save_gif_, &QPushButton::clicked, this, &Function::onGifSaveClicked);
  connect(clear_, &QPushButton::clicked, this, &Function::onClearClicked);
  connect(reset_, &QPushButton::clicked, this, &Function::onResetClicked);
}

void Function::onImageSaveClicked() {
  if (img_dialog_->exec() == QFileDialog::Accepted) {
    QString path{img_dialog_->selectedFiles().first()};
    QString select_filter{img_dialog_->selectedNameFilter()};

    QString format;
    if (select_filter.contains("bmp")) {
      format = "BMP";

      if (!path.endsWith(".bmp", Qt::CaseInsensitive)) {
        path += ".bmp";
      }
    } else {
      format = "JPEG";

      if (!path.endsWith(".jpeg", Qt::CaseInsensitive)) {
        path += ".jpeg";
      }
    }

    emit imageSave(path, format);
  }
}

void Function::onGifSaveClicked() {
  if (gif_dialog_->exec() == QFileDialog::Accepted) {
    QString path{gif_dialog_->selectedFiles().first()};
    QString select_filter{gif_dialog_->selectedNameFilter()};
    if (!path.endsWith(".gif", Qt::CaseInsensitive)) {
      path += ".gif";
    }

    emit gifSave(path);
  }
}

void Function::onClearClicked() { emit clear(); }

void Function::onResetClicked() { emit reset(); }
