/**
 * @file data.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_CONTROLLER_DATA_H_
#define SRC_INCLUDE_CONTROLLER_DATA_H_

#include <QColor>
#include <string>

enum class CalculateType { CPU, GPU };
enum class ProjectionType { Centrall, Parallel };
enum class VertexType { Square, Circle, None };
enum class FacetType { Solid, Dotted, None };

struct Data {
 public:
  std::string path;
  int rotate_x, rotate_y, rotate_z;
  int scale;
  int move_x, move_y, move_z;
  CalculateType calculate_type;
  ProjectionType projection_type;
  QColor background_color;
  VertexType vertex_type;
  FacetType facet_type;
  int vertex_size;
  int facet_size;
  QColor vertex_color;
  QColor facet_color;
};

#endif  // SRC_INCLUDE_CONTROLLER_DATA_H_
