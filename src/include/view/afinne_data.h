/**
 * @file afinne_data.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_AFINNE_DATA_H_
#define SRC_INCLUDE_VIEW_AFINNE_DATA_H_

#include <QWidget>

#include "include/view/slider.h"

class AfinneData : QWidget {
 public:
  AfinneData();
  ~AfinneData();

 private:
  void allocateMemory();
  void initView();
};

#endif  // SRC_INCLUDE_VIEW_AFINNE_DATA_H_
