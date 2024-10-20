/**
 * @file afinne_data.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief Implementation file for the AfinneData class
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/afinne_data.h"

namespace s21 {

/**
 * @brief Construct a new AfinneData object.
 *
 * @param title Pointer to the QLabel for the title of the widget.
 * @param sliders A list of slider labels to be displayed.
 * @param min Minimum value for the sliders.
 * @param max Maximum value for the sliders.
 */
AfinneData::AfinneData(QLabel *title, const QStringList &sliders, int min,
                       int max)
    : BaseWidget{title} {
  allocateMemory(sliders, min, max);
  initView();
}

/**
 * @brief Allocate memory for the sliders based on the given parameters.
 *
 * @param sliders A list of slider labels.
 * @param min Minimum value for the sliders.
 * @param max Maximum value for the sliders.
 */
void AfinneData::allocateMemory(const QStringList &sliders, int min, int max) {
  for (auto i : sliders) {
    sliders_.push_back(new Slider{i, min, max});
  }
}

/**
 * @brief Initialize the view components of the widget.
 *
 * This function sets up the layout and connects the signals and slots.
 */
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

/**
 * @brief Record the current data from the sliders.
 *
 * This function retrieves the values from the sliders and stores them
 * in the appropriate data structure.
 */
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

/**
 * @brief Set the data from the current configuration.
 *
 * This function updates the sliders' positions based on the stored data.
 */
void AfinneData::setData() {
  Data &data(Data::data());

  if (title() == "Rotate") {
    sliders_[0]->setValue(data.rotate_x);
    sliders_[1]->setValue(data.rotate_y);
    sliders_[2]->setValue(data.rotate_z);
  } else if (title() == "Scale") {
    sliders_[0]->setValue(100 * data.scale);
  } else {
    sliders_[0]->setValue(data.move_x);
    sliders_[1]->setValue(data.move_y);
    sliders_[2]->setValue(data.move_z);
  }
}

/**
 * @brief Slot to handle changes in slider data.
 *
 * This slot is triggered when the user adjusts a slider, allowing the
 * system to react accordingly.
 */
void AfinneData::onDataChanged() { emit dataChanged(); }

/**
 * @brief Reset the sliders to their default values.
 *
 * This function restores the sliders to their initial positions.
 */
void AfinneData::reset() {
  for (auto &slider : sliders_) {
    if (title() == "Scale") {
      slider->setValue(100);
    } else {
      slider->setValue(0);
    }
  }
}

}  // namespace s21
