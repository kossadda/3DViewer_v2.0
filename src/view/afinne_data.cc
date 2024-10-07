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
                       int max, int current)
    : BaseWidget{title} {
  allocateMemory(sliders, min, max);
  initView(current);
}

void AfinneData::allocateMemory(const QStringList &sliders, int min, int max) {
  for (auto i : sliders) {
    sliders_.push_back(new Slider{i, min, max});
  }
}

void AfinneData::initView(int current) {
  for (auto i : sliders_) {
    grid_->addWidget(i);
    i->setValue(current);
  }
}

void AfinneData::recordData(Data *data) {
  if (title() == "Rotate") {
    data->rotate_x = sliders_[0]->value();
    data->rotate_y = sliders_[1]->value();
    data->rotate_z = sliders_[2]->value();
  } else if (title() == "Scale") {
    data->scale = sliders_[0]->value();
  } else {
    data->move_x = sliders_[0]->value();
    data->move_y = sliders_[1]->value();
    data->move_z = sliders_[2]->value();
  }
}
