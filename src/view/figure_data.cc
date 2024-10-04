/**
 * @file figure_data.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief 
 * @version 1.0
 * @date 2024-10-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "include/view/figure_data.h"

FigureData::FigureData() : QWidget{} {
  allocateMemory();
  initView();
}

FigureData::~FigureData() {}

void FigureData::allocateMemory() {}

void FigureData::initView() {}
