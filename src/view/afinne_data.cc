/**
 * @file afinne_data.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/afinne_data.h"

AfinneData::AfinneData(QLabel *title, const QStringList &sliders, int min,
                       int max)
    : BaseWidget{title} {
  allocateMemory(sliders, min, max);
  initView();
}

void AfinneData::allocateMemory(const QStringList &sliders, int min, int max) {
  for (auto i : sliders) {
    sliders_.push_back(new Slider{i, min, max});
  }
}

void AfinneData::initView() {
  for (auto i : sliders_) {
    grid_->addWidget(i);
  }
}
