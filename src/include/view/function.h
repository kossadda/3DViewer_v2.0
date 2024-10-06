/**
 * @file function.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_FUNCTION_H_
#define SRC_INCLUDE_VIEW_FUNCTION_H_

#include <QGridLayout>
#include <QPushButton>
#include <QVector>
#include <QWidget>

#include "include/view/style.h"

class Function : public QWidget {
 public:
  Function();

 private:
  void allocateMemory();
  void initView();

  QGridLayout *grid_;
  QPushButton *save_img_;
  QPushButton *save_gif_;
  QPushButton *clear_;
  QPushButton *reset_;
};

#endif  // SRC_INCLUDE_VIEW_FUNCTION_H_
