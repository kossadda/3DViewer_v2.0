/**
 * @file afinne_data.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for the AfinneData class that manages affine
 * transformations
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_AFINNE_DATA_H_
#define SRC_INCLUDE_VIEW_AFINNE_DATA_H_

#include <QGridLayout>
#include <QVector>

#include "include/controller/data.h"
#include "include/view/base_widget.h"
#include "include/view/slider.h"

namespace s21 {

class AfinneData : public BaseWidget {
  Q_OBJECT

 public:
  AfinneData(QLabel *title, const QStringList &sliders, int min, int max);

  void recordData();
  void setData();
  void reset();

 signals:
  void dataChanged();

 private slots:
  void onDataChanged();

 private:
  void allocateMemory(const QStringList &sliders, int min, int max);
  void initView();

  QVector<Slider *> sliders_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_AFINNE_DATA_H_
