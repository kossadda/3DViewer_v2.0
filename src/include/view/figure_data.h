/**
 * @file figure_data.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_FIGURE_DATA_H_
#define SRC_INCLUDE_VIEW_FIGURE_DATA_H_

#include "include/view/base_widget.h"

class FigureData : public BaseWidget {
 public:
  FigureData();

 private:
  void allocateMemory();
  void initView();
};

#endif  // SRC_INCLUDE_VIEW_FIGURE_DATA_H_
