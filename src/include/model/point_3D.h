/**
 * @file point_3D.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Definition of a class representing a point in 3D space
 * @version 1.0
 * @date 2024-09-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_POINT_3D_H_
#define SRC_INCLUDE_MODEL_POINT_3D_H_

namespace s21 {

struct Point3D {
 public:
  Point3D() noexcept = default;
  Point3D(float x, float y, float z);
  inline const float* base() const noexcept { return &x; }

  bool operator==(const Point3D& other) const noexcept;
  float x{}, y{}, z{};
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_POINT_3D_H_
