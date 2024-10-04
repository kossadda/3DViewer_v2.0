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

Slider::Slider() : QWidget{} {
  allocateMemory();
  initView();
}

Slider::~Slider() {}

void Slider::allocateMemory() {
  slider_ = new QSlider;
  box_ = new QSpinBox;
}

void Slider::initView() {}
