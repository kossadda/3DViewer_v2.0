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

#include <QWidget>

#ifndef SRC_INCLUDE_VIEW_PATH_READER_H_
#define SRC_INCLUDE_VIEW_PATH_READER_H_

class PathReader : public QWidget {
 public:
  PathReader();
  ~PathReader();

 private:
  void allocateMemory();
  void initView();
};

#endif  // SRC_INCLUDE_VIEW_PATH_READER_H_
