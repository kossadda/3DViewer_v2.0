/**
 * @file 3DViewer.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <QApplication>

#include "include/view/main_window.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  MainWindow window;
  window.show();

  return a.exec();
}
