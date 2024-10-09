/**
 * @file scene_data.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_SCENE_DATA_H_
#define SRC_INCLUDE_VIEW_SCENE_DATA_H_

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>

#include "include/controller/data.h"
#include "include/view/base_widget.h"
#include "include/view/color_button.h"

namespace s21 {

class SceneData : public BaseWidget {
  Q_OBJECT

 public:
  explicit SceneData(QLabel *title);

  void recordData();

 signals:
  void dataChanged();

 private slots:
  void onDataChanged(int value = 0);

 private:
  void allocateMemory();
  void initView();

  QGridLayout *data_grid_;
  QLabel *calculate_label_;
  QLabel *projection_label_;
  QLabel *color_label_;
  QComboBox *calculate_combo_, *projection_combo_;
  ColorButton *color_button_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_SCENE_DATA_H_
