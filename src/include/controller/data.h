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
#include <iostream>
#include <string>

namespace s21 {

enum class CalculateType { CPU, GPU };
enum class ProjectionType { Centrall, Parallel };
enum class VertexType { Square, Circle, None };
enum class FacetType { Solid, Dotted, None };

struct Data {
 public:
  static Data& data() {
    static Data instance;
    return instance;
  }

  Data(const Data&) = delete;
  Data& operator=(const Data&) = delete;

  std::string path;
  int rotate_x{}, rotate_y{}, rotate_z{};
  float scale{1.0f};
  int move_x{}, move_y{}, move_z{};
  CalculateType calculate_type{CalculateType::CPU};
  ProjectionType projection_type{ProjectionType::Centrall};
  QColor background_color{Qt::black};
  VertexType vertex_type{VertexType::Square};
  FacetType facet_type{FacetType::Solid};
  int vertex_size{1};
  int facet_size{1};
  QColor vertex_color{64, 1, 5};
  QColor facet_color{64, 1, 5};

 private:
  Data() {}
};

}  // namespace s21

#endif  // SRC_INCLUDE_CONTROLLER_DATA_H_
