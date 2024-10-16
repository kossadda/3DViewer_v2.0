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

#include <QFileDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QTimer>
#include <QVector>
#include <QWidget>

#include "include/view/style.h"

namespace s21 {

class Function : public QWidget {
  Q_OBJECT

 public:
  Function();
  ~Function();

 signals:
  void imageSave(const QString &path, const QString &format);
  void gifSave(const QString &path);
  void clear();
  void reset();

 public slots:
  void changeStatus();

 private slots:
  void onCountDown();

 private:
  void onImageClicked();
  void onGifClicked();
  void onClearClicked();
  void onResetClicked();

  void allocateMemory();
  void initView();

  QGridLayout *grid_;
  QPushButton *save_img_;
  QPushButton *save_gif_;
  QPushButton *clear_;
  QPushButton *reset_;
  QFileDialog *img_dialog_;
  QFileDialog *gif_dialog_;

  QTimer *count_down_;
  QString path_;

  int count_;
  bool recording_{false};
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_FUNCTION_H_
