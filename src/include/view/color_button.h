/**
 * @file color_button.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_COLOR_BUTTON_H_
#define SRC_INCLUDE_VIEW_COLOR_BUTTON_H_

#include <QColor>
#include <QColorDialog>
#include <QPushButton>

#include "include/view/style.h"

class ColorButton : public QPushButton {
 public:
  explicit ColorButton(const QColor &color = QColor{Qt::black});
  ~ColorButton();

  QColor getColor();

 private slots:
  void setColor(const QColor &color);
  void onButtonClicked();

 private:
  QColorDialog *dialog_;
};

#endif  // SRC_INCLUDE_VIEW_COLOR_BUTTON_H_
