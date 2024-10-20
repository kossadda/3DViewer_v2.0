/**
 * @file main_window.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for the MainWindow class, providing the main application
 * interface
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_MAIN_WINDOW_H_
#define SRC_INCLUDE_VIEW_MAIN_WINDOW_H_

#include <QGridLayout>
#include <QSettings>
#include <QWidget>

#include "include/controller/data.h"
#include "include/view/afinne_data.h"
#include "include/view/function.h"
#include "include/view/object_data.h"
#include "include/view/path_reader.h"
#include "include/view/scene_data.h"
#include "include/view/scene_view.h"
#include "include/view/style.h"

namespace s21 {

/**
 * @class MainWindow
 * @brief The main application window for managing data and visual
 * representation.
 *
 * The MainWindow class serves as the primary interface for users to interact
 * with the application. It allows users to manipulate data, view scenes, and
 * configure settings. The class integrates various components to facilitate
 * user interaction with the application's functionalities.
 */
class MainWindow : public QWidget {
  Q_OBJECT

 public:
  MainWindow();
  void resetData();
  void resetAll();

 protected:
  void closeEvent(QCloseEvent *event) override;

 private:
  void allocateMemory();
  void initView();
  void recordData();
  void saveSettings() const;
  void loadSettings();

  Data &data_{Data::data()};

  QGridLayout *left_menu;
  PathReader *path_;
  SceneView *scene_;
  AfinneData *rotate_;
  AfinneData *scale_;
  AfinneData *move_;
  ObjectData *figure_;
  SceneData *setting_;
  Function *function_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_MAIN_WINDOW_H_
