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

namespace s21 {

class BaseWidget : public QWidget {
  Q_OBJECT

 public:
  explicit BaseWidget(QLabel *title = nullptr);

  QString title();
  void setIcon(int w, int h);

 private:
  virtual void allocateMemory(QLabel *title);
  virtual void initView();

  QFrame *frame_;
  QGridLayout *frame_grid_;
  QLabel *title_;

 protected:
  QGridLayout *grid_;
  QLabel *icon_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_BASE_WIDGET_H_
