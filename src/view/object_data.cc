/**
 * @file object_data.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/object_data.h"

ObjectData::ObjectData() : BaseWidget{} {
  allocateMemory();
  initView();
}

void ObjectData::allocateMemory() {
  data_grid_ = new QGridLayout;
  vertex_label_ = new QLabel{"  Vertex"};
  facet_label_ = new QLabel{"  Facet"};
  type_label_ = new QLabel{"   Type"};
  size_label_ = new QLabel{"   Size"};
  color_label_ = new QLabel{"   Color"};
  vtype_combo_ = new QComboBox;
  vsize_box_ = new QSpinBox;
  vcolor_button_ = new ColorButton{QColor{64, 1, 5}};
  ftype_combo_ = new QComboBox;
  fsize_box_ = new QSpinBox;
  fcolor_button_ = new ColorButton{QColor{64, 1, 5}};
}

void ObjectData::initView() {
  QVector<QLabel *> labels{type_label_, size_label_, color_label_,
                           vertex_label_, facet_label_};
  QString label_font_up{QString{Style::kLabelStyle}.replace("14px", "16px")};
  QString border_font_up{label_font_up += "border-radius: 10px;"};
  border_font_up.replace("none", "1px solid #636363");

  setIcon(35, 25);
  icon_->setPixmap({":line"});
  grid_->addLayout(data_grid_, 1, 0, Qt::AlignCenter);
  data_grid_->addWidget(icon_, 0, 0, Qt::AlignLeft | Qt::AlignVCenter);
  data_grid_->addWidget(type_label_, 1, 0);
  data_grid_->addWidget(size_label_, 2, 0);
  data_grid_->addWidget(color_label_, 3, 0);
  data_grid_->addWidget(vertex_label_, 0, 1, Qt::AlignCenter);
  data_grid_->addWidget(facet_label_, 0, 2, Qt::AlignCenter);
  data_grid_->addWidget(vtype_combo_, 1, 1, Qt::AlignCenter);
  data_grid_->addWidget(vsize_box_, 2, 1, Qt::AlignCenter);
  data_grid_->addWidget(vcolor_button_, 3, 1, Qt::AlignCenter);
  data_grid_->addWidget(ftype_combo_, 1, 2, Qt::AlignCenter);
  data_grid_->addWidget(fsize_box_, 2, 2, Qt::AlignCenter);
  data_grid_->addWidget(fcolor_button_, 3, 2, Qt::AlignCenter);
  data_grid_->setContentsMargins(0, 0, 0, 0);
  data_grid_->setVerticalSpacing(10);
  data_grid_->setHorizontalSpacing(5);

  for (auto label : labels) {
    label->setAlignment(Qt::AlignCenter);
    if (label != vertex_label_ && label != facet_label_) {
      label->setFixedWidth(110);
      label->setStyleSheet(border_font_up);
    } else {
      label->setStyleSheet(label_font_up);
    }
  }

  for (auto name : QStringList{"□", "○", "none"}) {
    vtype_combo_->addItem(name);
  }

  for (auto name : QStringList{"──", "----", "none"}) {
    ftype_combo_->addItem(name);
  }

  vsize_box_->setMinimum(1);
  vsize_box_->setMaximum(10);
  fsize_box_->setMinimum(1);
  fsize_box_->setMaximum(10);

  vtype_combo_->setFixedSize(70, 35);
  vsize_box_->setFixedSize(70, 35);
  vcolor_button_->setFixedSize(70, 35);
  ftype_combo_->setFixedSize(70, 35);
  fsize_box_->setFixedSize(70, 35);
  fcolor_button_->setFixedSize(70, 35);

  vtype_combo_->setStyleSheet(Style::kComboBoxStyle);
  vsize_box_->setStyleSheet(Style::kSpinBoxStyle);
  ftype_combo_->setStyleSheet(Style::kComboBoxStyle);
  fsize_box_->setStyleSheet(Style::kSpinBoxStyle);
}

void ObjectData::recordData(Data *data) {
  if (vtype_combo_->currentIndex() == 0) {
    data->vertex_type = VertexType::Square;
  } else if (vtype_combo_->currentIndex() == 1) {
    data->vertex_type = VertexType::Circle;
  } else {
    data->vertex_type = VertexType::None;
  }

  if (ftype_combo_->currentIndex() == 0) {
    data->facet_type = FacetType::Solid;
  } else if (ftype_combo_->currentIndex() == 1) {
    data->facet_type = FacetType::Dotted;
  } else {
    data->facet_type = FacetType::None;
  }

  data->vertex_size = vsize_box_->value();
  data->facet_size = fsize_box_->value();
  data->vertex_color = vcolor_button_->getColor();
  data->facet_color = fcolor_button_->getColor();
}
