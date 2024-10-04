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
#include <QGridLayout>
#include <QVector>

#include "include/view/slider.h"

class AfinneData : public QWidget {
 public:
  AfinneData(const QStringList &names, int min, int max);
  ~AfinneData();

 private:
  void allocateMemory(const QStringList &names, int min, int max);
  void initView();

  QGridLayout *grid_;
  QVector<Slider *> sliders_;
};

#endif  // SRC_INCLUDE_VIEW_AFINNE_DATA_H_
