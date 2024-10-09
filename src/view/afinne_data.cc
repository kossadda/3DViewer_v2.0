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

namespace s21 {

AfinneData::AfinneData(QLabel *title, const QStringList &sliders, int min, int max)
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
  if (title() == "Rotate") {
    icon_->setPixmap({":rotate"});
  } else if (title() == "Scale") {
    icon_->setPixmap({":scale"});
  } else {
    icon_->setPixmap({":move"});
  }

  for (auto slider : sliders_) {
    grid_->addWidget(slider);

    if (title() == "Scale") {
      slider->setValue(100 * Data::data().scale);    
    } else {
      slider->setValue(0);
    }
    
    connect(slider, &Slider::valueChanged, this, &AfinneData::dataChanged);
  }
}

void AfinneData::recordData() {
  Data &data{Data::data()};

  if (title() == "Rotate") {
    data.rotate_x = sliders_[0]->value();
    data.rotate_y = sliders_[1]->value();
    data.rotate_z = sliders_[2]->value();
  } else if (title() == "Scale") {
    data.scale = 0.01f * sliders_[0]->value();
  } else {
    data.move_x = sliders_[0]->value();
    data.move_y = sliders_[1]->value();
    data.move_z = sliders_[2]->value();
  }
}

void AfinneData::onDataChanged() {
  emit dataChanged();
}

void AfinneData::reset() {
  for(auto &slider : sliders_) {
    if (title() == "Scale") {
      slider->setValue(100);
    } else {
      slider->setValue(0);
    }
  }
}

}  // namespace s21
