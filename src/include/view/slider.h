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

#include <QSlider>
#include <QSpinBox>
#include <QLabel>
#include <QGridLayout>

#ifndef SRC_INCLUDE_VIEW_SLIDER_H_
#define SRC_INCLUDE_VIEW_SLIDER_H_

class Slider : public QWidget {
 public:
  Slider(const QString &name, int min, int max);
  ~Slider();

 private:
  void allocateMemory(const QString &name);
  void initView(int min, int max);

  QSlider *slider_;
  QSpinBox *box_;
  QLabel *label_;
  std::size_t value_;
};

#endif  // SRC_INCLUDE_VIEW_SLIDER_H_
