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
  label_ = new QLabel{name};
  slider_ = new QSlider{Qt::Horizontal};
  box_ = new QSpinBox;
}

void Slider::initView(int min, int max) {
  QGridLayout *grid{new QGridLayout};
  setLayout(grid);

  grid->addWidget(label_, 0, 0);
  grid->addWidget(slider_, 0, 1);
  grid->addWidget(box_, 0, 2);

  label_->setFixedSize(10, 30);
  slider_->setFixedSize(120, 30);
  box_->setFixedSize(60, 30);

  slider_->setMinimum(min);
  slider_->setMaximum(max);
  box_->setMinimum(min);
  box_->setMaximum(max);
}
