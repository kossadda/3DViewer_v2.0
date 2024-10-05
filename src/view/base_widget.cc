/**
 * @file base_widget.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/base_widget.h"

BaseWidget::BaseWidget(QLabel *title) : QWidget{} {
  allocateMemory();
  initView(title);
}

void BaseWidget::allocateMemory() {
  grid_ = new QGridLayout;
  frame_ = new QFrame;
}

void BaseWidget::initView(QLabel *title) {
  QGridLayout *main_grid{new QGridLayout};
  setLayout(main_grid);
  main_grid->setContentsMargins(1, 1, 1, 1);

  main_grid->addWidget(frame_);
  frame_->setLayout(grid_);

  if (title) {
    grid_->addWidget(title, 0, 0, Qt::AlignCenter);
    QString new_label_style{Style::kLabelStyle};
    title->setStyleSheet(new_label_style.replace("12px", "15px"));
  }

  setStyleSheet(Style::kWindowStyle);
  frame_->setStyleSheet(Style::kFrameStyle);
}
