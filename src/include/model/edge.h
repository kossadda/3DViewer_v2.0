/**
 * @file edge.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_EDGE_H_
#define SRC_INCLUDE_MODEL_EDGE_H_

#include "include/model/vertex.h"

namespace s21 {
class Edge {
 public:
  Edge(int begin, int end) noexcept;
  inline int begin() const noexcept { return begin_; }
  inline int end() const noexcept { return end_; }

 private:
  int begin_;
  int end_;
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_EDGE_H_
