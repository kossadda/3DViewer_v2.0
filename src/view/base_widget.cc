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
  allocateMemory(title);
  initView();
}

void BaseWidget::allocateMemory(QLabel *title) {
  grid_ = new QGridLayout;
  frame_grid_ = new QGridLayout;
  frame_ = new QFrame;
  title_ = title;
}

void BaseWidget::initView() {
  QGridLayout *title_grid{new QGridLayout};
  setLayout(frame_grid_);
  frame_grid_->setContentsMargins(1, 1, 1, 1);

  frame_grid_->addWidget(frame_);
  frame_->setLayout(grid_);

  grid_->setVerticalSpacing(4);
  grid_->addLayout(title_grid, 0, 0, Qt::AlignTop);

  if (title_) {
    setIcon(40, 25);

    title_grid->addWidget(icon_, 0, 0);
    title_grid->addWidget(title_, 0, 1, Qt::AlignCenter);
    title_->setStyleSheet(QString{Style::kLabelStyle}.replace("14px", "15px"));
  }

  setStyleSheet(Style::kWindowStyle);
  frame_->setStyleSheet(Style::kFrameStyle);
}

QString BaseWidget::title() { return (title_) ? title_->text() : QString{}; }

void BaseWidget::setIcon(int w, int h) {
  icon_ = new QLabel;
  icon_->setStyleSheet(Style::kLabelStyle);
  icon_->setFixedSize(w, h);
  icon_->setScaledContents(true);
}
