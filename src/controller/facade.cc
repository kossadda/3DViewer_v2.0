/**
 * @file facade.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/controller/facade.h"

namespace s21 {

/**
 * @brief Constructs a new Facade object, initializing the necessary components
 * for scene management and rendering.
 */
Facade::Facade() {
  file_reader_ = new FileReader;
  scene_drawer_ = new SceneDrawer;

  connect(scene_drawer_, &SceneDrawerBase::recorded, this, &Facade::onRecorded);
}

/**
 * @brief Destroys the Facade object, cleaning up the dynamically allocated
 * resources.
 */
Facade::~Facade() {
  delete file_reader_;
  delete scene_drawer_;
  delete scene_;
}

/**
 * @brief Loads a scene from a file.
 *
 * @param path The file path to load the scene from.
 *
 * This function reads the 3D scene information (vertices, edges, etc.) from the
 * specified file and initializes the scene for rendering.
 */
void Facade::loadScene(const std::string &path) {
  scene_drawer_->clearScene();
  delete scene_;
  scene_ = file_reader_->ReadScene(path);
  drawScene();
}

/**
 * @brief Draws the loaded scene using the associated rendering system.
 *
 * This function calls the underlying rendering logic to display the scene on
 * the screen or in a specific view.
 */
void Facade::drawScene() { scene_drawer_->drawScene(scene_); }

/**
 * @brief Saves the currently drawn scene as an image file.
 *
 * @param path The file path where the image should be saved.
 * @param format The format of the image file (e.g., PNG, JPG).
 *
 * This function exports the drawn scene as an image file in the specified
 * format.
 */
void Facade::saveImage(const std::string &path, const std::string format) {
  scene_drawer_->saveImage(path, format);
}

/**
 * @brief Saves the currently drawn scene as a GIF file.
 *
 * @param path The file path where the GIF should be saved.
 *
 * This function exports the scene as an animated GIF.
 */
void Facade::saveGif(const std::string &path) { scene_drawer_->saveGif(path); }

/**
 * @brief Slot to handle the recording event, performing necessary actions after
 * a scene has been recorded.
 */
void Facade::onRecorded() { emit recorded(); }

/**
 * @brief Returns the number of vertices in the current scene.
 *
 * @return std::size_t The number of vertices.
 *
 * This function provides information about how many vertices are present in the
 * loaded scene.
 */
std::size_t Facade::numberOfVerticies() {
  return (scene_) ? scene_->vertices().size() : 0;
}

/**
 * @brief Returns the number of edges in the current scene.
 *
 * @return std::size_t The number of edges.
 *
 * This function provides information about how many edges are present in the
 * loaded scene.
 */
std::size_t Facade::numberOfEdges() {
  return (scene_) ? scene_->indices().size() : 0;
}

}  // namespace s21
