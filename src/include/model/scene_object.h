/**
 * @file scene_object.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Abstract base class for scene object
 * @version 1.0
 * @date 2024-09-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_SCENE_OBJECT_H_
#define SRC_INCLUDE_MODEL_SCENE_OBJECT_H_

#include "include/model/transform_matrix.h"

namespace s21 {
class SceneObject {
  virtual ~SceneObject() = default;
  virtual void Transform(const TransformMatrix &matrix) = 0;
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_SCENE_OBJECT_H_
