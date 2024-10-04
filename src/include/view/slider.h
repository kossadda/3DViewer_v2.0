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

#ifndef SRC_INCLUDE_VIEW_SLIDER_H_
#define SRC_INCLUDE_VIEW_SLIDER_H_

class Slider : QWidget {
 public:
  Slider();
  ~Slider();

 private:
  void allocateMemory();
  void initView();

  QSlider *slider_;
  QSpinBox *box_;
  std::size_t value_;
};

#endif  // SRC_INCLUDE_VIEW_SLIDER_H_
