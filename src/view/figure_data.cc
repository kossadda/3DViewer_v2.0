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

FigureData::FigureData(QLabel *title, const QStringList &buttons_name)
    : BaseWidget{title} {
  allocateMemory();
  initView(buttons_name);
}

void FigureData::allocateMemory() {
  data_grid_ = new QGridLayout;
  type_label_ = new QLabel{"Type"};
  size_label_ = new QLabel{"Size"};
  color_label_ = new QLabel{"Color"};
  type_combo_ = new QComboBox;
  size_box_ = new QSpinBox;
  color_button_ = new QPushButton{"Choose"};
}

void FigureData::initView(const QStringList &buttons_name) {
  QVector<QLabel *> labels{type_label_, size_label_, color_label_};
  QString label_font_up{QString{Style::kLabelStyle}.replace("14px", "16px")};

  grid_->addLayout(data_grid_, 1, 0, Qt::AlignCenter);
  data_grid_->addWidget(type_label_, 0, 0);
  data_grid_->addWidget(size_label_, 1, 0);
  data_grid_->addWidget(color_label_, 2, 0);
  data_grid_->addWidget(type_combo_, 0, 1, Qt::AlignCenter);
  data_grid_->addWidget(size_box_, 1, 1, Qt::AlignCenter);
  data_grid_->addWidget(color_button_, 2, 1, Qt::AlignCenter);
  data_grid_->setVerticalSpacing(10);

  for (auto label : labels) {
    label->setStyleSheet(label_font_up);
    label->setFixedSize(80, 35);
    label->setAlignment(Qt::AlignCenter);
  }

  for (auto name : buttons_name) {
    type_combo_->addItem(name);
  }

  type_combo_->setFixedSize(100, 35);
  size_box_->setFixedSize(100, 35);
  color_button_->setFixedSize(100, 35);

  type_combo_->setStyleSheet(Style::kComboBoxStyle);
  size_box_->setStyleSheet(Style::kSpinBoxStyle);
  color_button_->setStyleSheet(Style::kButtonStyle);
}
