/**
 * @file style.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file that declares the Style class containing various styles
 * for the application
 * @version 1.0
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_STYLE_H_
#define SRC_INCLUDE_VIEW_STYLE_H_

#include <QString>

namespace s21 {

/**
 * @class Style
 * @brief A class that holds style definitions for UI components.
 *
 */
class Style {
 public:
  static const QString kWindowTranparentStyle;
  static const QString kWindowStyle;
  static const QString kFrameStyle;
  static const QString kSliderStyle;
  static const QString kLabelStyle;
  static const QString kSpinBoxStyle;
  static const QString kButtonStyle;
  static const QString kColorButtonStyle;
  static const QString kLineEditStyle;
  static const QString kComboBoxStyle;
  static const QString kFileDialogStyle;
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_STYLE_H_
