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

void Slider::allocateMemory(const QString &name) {
  grid_ = new QGridLayout;
  label_ = new QLabel{name};
  slider_ = new QSlider{Qt::Horizontal};
  box_ = new QSpinBox;
}

void Slider::initView(int min, int max) {
  setLayout(grid_);
  grid_->setHorizontalSpacing(10);

  grid_->addWidget(label_, 0, 0);
  grid_->addWidget(slider_, 0, 1, Qt::AlignLeft);
  grid_->addWidget(box_, 0, 2);

  slider_->setMinimum(min);
  slider_->setMaximum(max);
  box_->setMinimum(min);
  box_->setMaximum(max);

  label_->setFixedSize(30, 27);
  box_->setFixedSize(70, 27);
  slider_->setFixedSize(150, 30);

  setStyleSheet(Style::kWindowTranparentStyle);
  label_->setStyleSheet(Style::kLabelStyle);
  slider_->setStyleSheet(Style::kSliderStyle);
  box_->setStyleSheet(Style::kSpinBoxStyle);

  connect(box_, &QSpinBox::valueChanged, this, &Slider::onValueChanged);
  connect(slider_, &QSlider::valueChanged, this, &Slider::onValueChanged);
}

void Slider::onValueChanged(int value) {
  slider_->setValue(value);
  box_->setValue(value);
}

void Slider::setValue(int value) { slider_->setValue(value); }
