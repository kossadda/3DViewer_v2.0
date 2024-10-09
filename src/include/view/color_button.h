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

namespace s21 {

class ColorButton : public QPushButton {
  Q_OBJECT

 public:
  explicit ColorButton(const QColor &color);
  ~ColorButton();

  QColor getColor();
  void setColor(const QColor &color);

 signals:
  void colorChanged(int value);

 private slots:
  void onButtonClicked();

 private:
  QColorDialog *dialog_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_COLOR_BUTTON_H_
