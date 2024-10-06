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
  reset_ = new QPushButton{"Reset"};
  clear_ = new QPushButton{"Clear scene"};
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
}
