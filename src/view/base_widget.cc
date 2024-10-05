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

BaseWidget::BaseWidget() : QWidget{} {
  allocateMemory();
  initView();
}

void BaseWidget::allocateMemory() {
  grid_ = new QGridLayout;
  frame_ = new QFrame;
}

void BaseWidget::initView() {
  QGridLayout *main_grid{new QGridLayout};
  setLayout(main_grid);
  // setFixedSize(300, 180);

  main_grid->addWidget(frame_);
  frame_->setLayout(grid_);
  frame_->setStyleSheet(Style::kFrameStyle);
}
