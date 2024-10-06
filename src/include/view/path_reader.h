/**
 * @file path_reader.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_PATH_READER_H_
#define SRC_INCLUDE_VIEW_PATH_READER_H_

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QPair>

#include "include/view/base_widget.h"
#include "include/view/style.h"

class PathReader : public BaseWidget {
  Q_OBJECT
  
 public:
  PathReader();

  void setInfo(int vertex_count, int facet_count);

 private slots:
  void onButtonClicked();
  void validPath();

 signals:
  void valid(const QString& path);

 private:
  void allocateMemory();
  void initView();

  QPushButton *path_button_;
  QLineEdit *path_edit_;
  QLabel *vertex_info_;
  QLabel *facet_info_;
  QFileDialog *dialog_;
};

#endif  // SRC_INCLUDE_VIEW_PATH_READER_H_
