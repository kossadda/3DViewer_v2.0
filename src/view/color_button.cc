/**
 * @file color_button.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/color_button.h"

namespace s21 {

ColorButton::ColorButton(const QColor &color) {
  dialog_ = new QColorDialog{color};
  setColor(color);
  connect(this, &QPushButton::clicked, this, &ColorButton::onButtonClicked);
}

ColorButton::~ColorButton() { delete dialog_; }

void ColorButton::onButtonClicked() {
  if (dialog_->exec() == QDialog::Accepted) {
    setColor(dialog_->currentColor());
  }
}

QColor ColorButton::getColor() { return dialog_->currentColor(); }

void ColorButton::setColor(const QColor &color) {
  QString new_color{Style::kColorButtonStyle};
  setStyleSheet(new_color.replace("-color:", "-color:" + color.name()));
  dialog_->setCurrentColor(color);
  emit colorChanged(0);
}

}  // namespace s21
