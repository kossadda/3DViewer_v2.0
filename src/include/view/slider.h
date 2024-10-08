/**
 * @file slider.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_SLIDER_H_
#define SRC_INCLUDE_VIEW_SLIDER_H_

#include <QGridLayout>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>

#include "include/view/style.h"

namespace s21 {

class Slider : public QWidget {
  Q_OBJECT

 public:
  Slider(const QString &name, int min, int max);

  int value();
  void setValue(int value);

 signals:
  void valueChanged();

 private slots:
  void onValueChanged(int value);

 private:
  void allocateMemory(const QString &name);
  void initView(int min, int max);

  QGridLayout *grid_;
  QSlider *slider_;
  QSpinBox *box_;
  QLabel *label_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_SLIDER_H_
