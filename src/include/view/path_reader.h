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

#include "include/view/base_widget.h"
#include "include/view/style.h"

class PathReader : public BaseWidget {
 public:
  PathReader();

 private:
  void allocateMemory();
  void initView();

  QPushButton *path_button_;
  QLineEdit *path_edit_;
  QLabel *vertex_info_;
  QLabel *facet_info_;
};

#endif  // SRC_INCLUDE_VIEW_PATH_READER_H_
