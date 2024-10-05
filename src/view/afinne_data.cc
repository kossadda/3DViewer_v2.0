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

AfinneData::AfinneData(const QStringList &names, int min, int max)
    : BaseWidget{} {
  allocateMemory(names, min, max);
  initView();
}

AfinneData::~AfinneData() {}

void AfinneData::allocateMemory(const QStringList &names, int min, int max) {
  for (auto i : names) {
    sliders_.push_back(new Slider{i, min, max});
  }
}

void AfinneData::initView() {
  for (auto i : sliders_) {
    grid_->addWidget(i);
  }
}
