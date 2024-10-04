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

AfinneData::AfinneData(const QStringList &names, int min, int max) : QWidget{} {
  allocateMemory(names, min, max);
  initView();
}

AfinneData::~AfinneData() {}

void AfinneData::allocateMemory(const QStringList &names, int min, int max) {
  grid_ = new QGridLayout;
  for(auto i : names) {
    sliders_.push_back(new Slider{i, min, max});
  }
}

void AfinneData::initView() {
  setLayout(grid_);
  setFixedSize(250, 140);

  for(auto i : sliders_) {
    grid_->addWidget(i);
  }
}
