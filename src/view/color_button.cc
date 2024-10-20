/**
 * @file color_button.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief Implementation of the ColorButton class
 * @version 1.0
 * @date 2024-10-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/color_button.h"

namespace s21 {

/**
 * @brief Construct a new ColorButton object.
 *
 * @param color Initial color for the button.
 */
ColorButton::ColorButton(const QColor &color) {
  dialog_ = new QColorDialog{color};
  setColor(color);
  connect(this, &QPushButton::clicked, this, &ColorButton::onButtonClicked);
}

/**
 * @brief Destroy the ColorButton object.
 */
ColorButton::~ColorButton() { delete dialog_; }

/**
 * @brief Slot that handles button click events.
 *
 * Opens a QColorDialog to allow the user to select a new color.
 * Emits the colorChanged signal when a new color is selected.
 */
void ColorButton::onButtonClicked() {
  if (dialog_->exec() == QDialog::Accepted) {
    setColor(dialog_->currentColor());
  }
}

/**
 * @brief Get the currently selected color.
 *
 * @return QColor The currently selected color.
 */
QColor ColorButton::getColor() { return dialog_->currentColor(); }

/**
 * @brief Set a new color for the button.
 *
 * @param color The new color to set.
 */
void ColorButton::setColor(const QColor &color) {
  QString new_color{Style::kColorButtonStyle};
  setStyleSheet(new_color.replace("-color:", "-color:" + color.name()));
  dialog_->setCurrentColor(color);
  emit colorChanged(0);
}

}  // namespace s21
