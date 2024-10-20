/**
 * @file slider.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief Implementation of the Slider class
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/slider.h"

namespace s21 {

/**
 * @brief Constructs a Slider widget.
 * @param name The label text displayed next to the slider.
 * @param min The minimum value for the slider and spin box.
 * @param max The maximum value for the slider and spin box.
 */
Slider::Slider(const QString &name, int min, int max) : QWidget{} {
  allocateMemory(name);
  initView(min, max);
}

/**
 * @brief Allocates memory for the layout and UI elements (label, slider, and
 * spin box).
 * @param name The label text to display.
 */
void Slider::allocateMemory(const QString &name) {
  grid_ = new QGridLayout;
  label_ = new QLabel{name};
  slider_ = new QSlider{Qt::Horizontal};
  box_ = new QSpinBox;
}

/**
 * @brief Sets up the layout, range, and appearance of the slider and spin box.
 * @param min The minimum value.
 * @param max The maximum value.
 */
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

  label_->setFixedSize(35, 27);
  box_->setFixedSize(70, 27);
  slider_->setFixedSize(140, 27);

  setStyleSheet(Style::kWindowTranparentStyle);
  label_->setStyleSheet(Style::kLabelStyle);
  slider_->setStyleSheet(Style::kSliderStyle);
  box_->setStyleSheet(Style::kSpinBoxStyle);

  connect(box_, &QSpinBox::valueChanged, this, &Slider::onValueChanged);
  connect(slider_, &QSlider::valueChanged, this, &Slider::onValueChanged);
}

/**
 * @brief Synchronizes the values between the slider and the spin box and emits
 * a signal when the value changes.
 * @param value The new value.
 */
void Slider::onValueChanged(int value) {
  slider_->setValue(value);
  box_->setValue(value);
  emit valueChanged();
}

/**
 * @brief Sets the slider to a specific value.
 * @param value The value to set.
 */
void Slider::setValue(int value) { slider_->setValue(value); }

/**
 * @brief Retrieves the current value of the slider.
 * @return The current value of the slider.
 */
int Slider::value() const { return slider_->value(); }

}  // namespace s21
