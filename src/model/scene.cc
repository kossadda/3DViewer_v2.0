/**
 * @file scene.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Implementation file for the Scene class
 * @version 1.0
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/scene.h"

namespace s21 {

/**
 * @brief Constructor to initialize a Scene with given indices, vertices, and
 * normalization parameter.
 *
 * This constructor initializes the scene with a set of indices and vertices,
 * and normalizes the vertices by the given normalization parameter. It is
 * marked noexcept to ensure it does not throw any exceptions.
 *
 * @param indices A constant reference to a vector of integers representing
 * vertex indices.
 * @param vertices A constant reference to a vector of Vertex objects
 * representing the scene vertices.
 * @param normalize_param A float value used to normalize the vertices.
 */
Scene::Scene(const std::vector<int>& indices,
             const std::vector<Vertex>& vertices, float normalize_param)
    : indices_{indices} {
  for (Vertex vertex : vertices) {
    data_.emplace_back(vertex.Normalize(normalize_param));
  }

  vertices_ = data_;
}

/**
 * @brief Transforms the scene using the given transformation matrix.
 *
 * Applies a transformation matrix to all vertices in the scene, updating their
 * positions accordingly. This method is marked noexcept, ensuring no exceptions
 * are thrown during the transformation process.
 *
 * @param matrix A constant reference to the TransformMatrix object to apply to
 * the vertices.
 */
void Scene::Transform(const TransformMatrix& matrix) {
  for (std::size_t i{}; i < data_.size(); ++i) {
    vertices_[i] = data_[i].Transform(matrix);
  }
}

}  // namespace s21
