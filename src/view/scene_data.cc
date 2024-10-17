/**
 * @file scene_data.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/scene_data.h"

namespace s21 {

SceneData::SceneData(QLabel *title) : BaseWidget{title} {
  allocateMemory();
  initView();
}

void SceneData::allocateMemory() {
  data_grid_ = new QGridLayout;
  calculate_label_ = new QLabel{"   Calculate"};
  projection_label_ = new QLabel{"   Projection"};
  color_label_ = new QLabel{"   Color"};
  calculate_combo_ = new QComboBox;
  projection_combo_ = new QComboBox;
  color_button_ = new ColorButton{Data::data().background_color};
}

void SceneData::initView() {
  QVector<QLabel *> labels{calculate_label_, projection_label_, color_label_};
  QString label_font_up{QString{Style::kLabelStyle}.replace("14px", "16px")};
  label_font_up.replace("none", "1px solid #636363");
  label_font_up += "border-radius: 10px;";
  icon_->setPixmap({":setting"});

  grid_->addLayout(data_grid_, 1, 0, Qt::AlignCenter);
  data_grid_->addWidget(calculate_label_, 0, 0);
  data_grid_->addWidget(projection_label_, 1, 0);
  data_grid_->addWidget(color_label_, 2, 0);
  data_grid_->addWidget(calculate_combo_, 0, 1, Qt::AlignCenter);
  data_grid_->addWidget(projection_combo_, 1, 1, Qt::AlignCenter);
  data_grid_->addWidget(color_button_, 2, 1, Qt::AlignCenter);
  data_grid_->setContentsMargins(0, 0, 0, 10);
  data_grid_->setVerticalSpacing(10);
  data_grid_->setHorizontalSpacing(10);

  for (auto label : labels) {
    label->setStyleSheet(label_font_up);
    label->setAlignment(Qt::AlignCenter);
    label->setFixedWidth(110);
  }

  for (auto name : QStringList{"CPU", "GPU"}) {
    calculate_combo_->addItem(name);
  }

  for (auto name : QStringList{"Central", "Parallel"}) {
    projection_combo_->addItem(name);
  }

  calculate_combo_->setCurrentIndex(
      static_cast<int>(Data::data().calculate_type));
  projection_combo_->setCurrentIndex(
      static_cast<int>(Data::data().projection_type));

  calculate_combo_->setFixedSize(145, 35);
  projection_combo_->setFixedSize(145, 35);
  color_button_->setFixedSize(145, 35);

  calculate_combo_->setStyleSheet(Style::kComboBoxStyle);
  projection_combo_->setStyleSheet(Style::kComboBoxStyle);

  connect(calculate_combo_, &QComboBox::currentIndexChanged, this,
          &SceneData::onDataChanged);
  connect(projection_combo_, &QComboBox::currentIndexChanged, this,
          &SceneData::onDataChanged);
  connect(color_button_, &ColorButton::colorChanged, this,
          &SceneData::onDataChanged);
}

void SceneData::onDataChanged(int value) {
  (void)value;
  emit dataChanged();
}

void SceneData::recordData() {
  Data &data{Data::data()};

  if (calculate_combo_->currentIndex() == 0) {
    data.calculate_type = CalculateType::CPU;
  } else {
    data.calculate_type = CalculateType::GPU;
  }

  if (projection_combo_->currentIndex() == 0) {
    data.projection_type = ProjectionType::Centrall;
  } else {
    data.projection_type = ProjectionType::Parallel;
  }

  data.background_color = color_button_->getColor();
}

void SceneData::reset() {
  calculate_combo_->setCurrentIndex(0);
  projection_combo_->setCurrentIndex(0);
  color_button_->setColor(Qt::black);
}

}  // namespace s21
