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

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QVector>

#include "include/view/base_widget.h"
#include "include/view/style.h"

class FigureData : public BaseWidget {
 public:
  FigureData();

 private:
  void allocateMemory();
  void initView();

  QGridLayout *data_grid_;
  QLabel *vertex_label_;
  QLabel *facet_label_;
  QLabel *type_label_;
  QLabel *size_label_;
  QLabel *color_label_;
  QComboBox *vtype_combo_, *ftype_combo_;
  QSpinBox *vsize_box_, *fsize_box_;
  QPushButton *vcolor_button_, *fcolor_button_;
};

#endif  // SRC_INCLUDE_VIEW_FIGURE_DATA_H_
