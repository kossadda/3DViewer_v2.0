/**
 * @file afinne_data.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/afinne_data.h"

AfinneData::AfinneData() : QWidget{} {
  allocateMemory();
  initView();
}

AfinneData::~AfinneData() {}

void AfinneData::allocateMemory() {}

void AfinneData::initView() {}
