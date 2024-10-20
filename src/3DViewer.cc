/**
 * @file 3DViewer.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Entry point for the 3D Viewer application
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

  s21::MainWindow window;
  window.show();

  return a.exec();
}
