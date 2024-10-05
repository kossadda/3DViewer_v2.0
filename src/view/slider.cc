/**
 * @file slider.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/slider.h"

Slider::Slider(const QString &name, int min, int max) : QWidget{} {
  allocateMemory(name);
  initView(min, max);
}

Slider::~Slider() {}

void Slider::allocateMemory(const QString &name) {
  grid_ = new QGridLayout;
  label_ = new QLabel{name};
  slider_ = new QSlider{Qt::Horizontal};
  box_ = new QSpinBox;
}

void Slider::initView(int min, int max) {
  setLayout(grid_);

  grid_->addWidget(label_, 0, 0);
  grid_->addWidget(slider_, 0, 1);
  grid_->addWidget(box_, 0, 2);

  slider_->setMinimum(min);
  slider_->setMaximum(max);
  box_->setMinimum(min);
  box_->setMaximum(max);

  setStyleSheet(Style::kWindowStyle);
  label_->setStyleSheet(Style::kLabelStyle);
  slider_->setStyleSheet(Style::kSliderStyle);
}
