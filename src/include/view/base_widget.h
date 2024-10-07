/**
 * @file base_widget.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_BASE_WIDGET_H_
#define SRC_INCLUDE_VIEW_BASE_WIDGET_H_

#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QWidget>

#include "include/view/style.h"

class BaseWidget : public QWidget {
  Q_OBJECT

 public:
  explicit BaseWidget(QLabel *title = nullptr);

 private:
  virtual void allocateMemory();
  virtual void initView(QLabel *title);

  QFrame *frame_;

 protected:
  QGridLayout *frame_grid_;
  QGridLayout *grid_;
};

#endif  // SRC_INCLUDE_VIEW_BASE_WIDGET_H_
