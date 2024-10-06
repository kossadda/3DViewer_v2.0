/**
 * @file figure_data.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/figure_data.h"

FigureData::FigureData() : BaseWidget{} {
  allocateMemory();
  initView();
}

void FigureData::allocateMemory() {
  data_grid_ = new QGridLayout;
  vertex_label_ = new QLabel{" Vertex"};
  facet_label_ = new QLabel{" Facet"};
  type_label_ = new QLabel{"Type"};
  size_label_ = new QLabel{"Size"};
  color_label_ = new QLabel{"Color"};
  vtype_combo_ = new QComboBox;
  vsize_box_ = new QSpinBox;
  vcolor_button_ = new QPushButton{"Choose"};
  ftype_combo_ = new QComboBox;
  fsize_box_ = new QSpinBox;
  fcolor_button_ = new QPushButton{"Choose"};
}

void FigureData::initView() {
  QVector<QLabel *> labels{type_label_, size_label_, color_label_,
                           vertex_label_, facet_label_};
  QString label_font_up{QString{Style::kLabelStyle}.replace("14px", "16px")};

  grid_->addLayout(data_grid_, 1, 0, Qt::AlignCenter);
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
  data_grid_->setVerticalSpacing(10);
  data_grid_->setHorizontalSpacing(10);

  for (auto label : labels) {
    label->setStyleSheet(label_font_up);
    label->setFixedSize(70, 25);
    label->setAlignment(Qt::AlignCenter);
  }

  for (auto name : QStringList{"□", "○", "none"}) {
    vtype_combo_->addItem(name);
  }

  for (auto name : QStringList{"──", "----", "none"}) {
    ftype_combo_->addItem(name);
  }

  vtype_combo_->setFixedSize(100, 35);
  vsize_box_->setFixedSize(100, 35);
  vcolor_button_->setFixedSize(100, 35);
  ftype_combo_->setFixedSize(100, 35);
  fsize_box_->setFixedSize(100, 35);
  fcolor_button_->setFixedSize(100, 35);

  vtype_combo_->setStyleSheet(Style::kComboBoxStyle);
  vsize_box_->setStyleSheet(Style::kSpinBoxStyle);
  vcolor_button_->setStyleSheet(Style::kButtonStyle);
  ftype_combo_->setStyleSheet(Style::kComboBoxStyle);
  fsize_box_->setStyleSheet(Style::kSpinBoxStyle);
  fcolor_button_->setStyleSheet(Style::kButtonStyle);
}
