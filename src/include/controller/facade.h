/**
 * @file facade.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Declaration of the Facade class for managing 3D scenes
 * @version 1.0
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_CONTROLLER_FACADE_H_
#define SRC_INCLUDE_CONTROLLER_FACADE_H_

#include <QObject>
#include <string>

#include "include/model/file_reader.h"
#include "include/model/file_reader_base.h"
#include "include/model/scene.h"
#include "include/model/scene_drawer.h"
#include "include/model/scene_drawer_base.h"

namespace s21 {

/**
 * @class Facade
 * @brief Provides a simplified interface to manage the loading, drawing, and
 * saving of 3D scenes.
 *
 * The Facade class hides the complexity of interacting with the underlying
 * scene, file readers, and rendering logic. It provides high-level methods to
 * load a scene from a file, draw the scene, save the resulting image, and
 * export it as a GIF. This class follows the Facade design pattern to simplify
 * the interface for the user.
 */
class Facade : public QObject {
  Q_OBJECT

 public:
  Facade();
  ~Facade();

  void loadScene(const std::string &path);
  void drawScene();
  void saveImage(const std::string &path, const std::string format);
  void saveGif(const std::string &path);

  std::size_t numberOfVerticies();
  std::size_t numberOfEdges();
  SceneDrawerBase *getView() { return scene_drawer_; }

 signals:
  void recorded();

 private slots:
  void onRecorded();

 private:
  SceneDrawerBase *scene_drawer_;
  FileReaderBase *file_reader_;
  Scene *scene_{};
};

}  // namespace s21

#endif  // SRC_INCLUDE_CONTROLLER_FACADE_H_
