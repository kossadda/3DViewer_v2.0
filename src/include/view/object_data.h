/**
 * @file object_data.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_OBJECT_DATA_H_
#define SRC_INCLUDE_VIEW_OBJECT_DATA_H_

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QVector>

#include "include/controller/data.h"
#include "include/view/base_widget.h"
#include "include/view/color_button.h"
#include "include/view/style.h"

namespace s21 {

class ObjectData : public BaseWidget {
  Q_OBJECT

 public:
  ObjectData();

  void recordData();

 signals:
  void dataChanged();

 private slots:
  void onDataChanged(int value);

 private:
  void allocateMemory();
  void initView();

  QGridLayout *data_grid_;
  QLabel *lvertex_, *lfacet_, *ltype_, *lsize_, *lcolor_;
  QComboBox *vtype_, *ftype_;
  QSpinBox *vsize_, *fsize_;
  ColorButton *vcolor_, *fcolor_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_OBJECT_DATA_H_
