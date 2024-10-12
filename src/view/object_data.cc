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

namespace s21 {

ObjectData::ObjectData() : BaseWidget{} {
  allocateMemory();
  initView();
}

void ObjectData::allocateMemory() {
  data_grid_ = new QGridLayout;
  lvertex_ = new QLabel{"  Vertex"};
  lfacet_ = new QLabel{"  Facet"};
  ltype_ = new QLabel{"   Type"};
  lsize_ = new QLabel{"   Size"};
  lcolor_ = new QLabel{"   Color"};
  vtype_ = new QComboBox;
  vsize_ = new QSpinBox;
  vcolor_ = new ColorButton{Data::data().vertex_color};
  ftype_ = new QComboBox;
  fsize_ = new QSpinBox;
  fcolor_ = new ColorButton{Data::data().facet_color};
}

void ObjectData::initView() {
  QVector<QLabel *> labels{ltype_, lsize_, lcolor_, lvertex_, lfacet_};
  QString label_font_up{QString{Style::kLabelStyle}.replace("14px", "16px")};
  QString border_font_up{label_font_up += "border-radius: 10px;"};
  border_font_up.replace("none", "1px solid #636363");

  setIcon(35, 25);
  icon_->setPixmap({":line"});
  grid_->addLayout(data_grid_, 1, 0, Qt::AlignCenter);
  data_grid_->addWidget(icon_, 0, 0, Qt::AlignLeft | Qt::AlignVCenter);
  data_grid_->addWidget(ltype_, 1, 0);
  data_grid_->addWidget(lsize_, 2, 0);
  data_grid_->addWidget(lcolor_, 3, 0);
  data_grid_->addWidget(lvertex_, 0, 1, Qt::AlignCenter);
  data_grid_->addWidget(lfacet_, 0, 2, Qt::AlignCenter);
  data_grid_->addWidget(vtype_, 1, 1, Qt::AlignCenter);
  data_grid_->addWidget(vsize_, 2, 1, Qt::AlignCenter);
  data_grid_->addWidget(vcolor_, 3, 1, Qt::AlignCenter);
  data_grid_->addWidget(ftype_, 1, 2, Qt::AlignCenter);
  data_grid_->addWidget(fsize_, 2, 2, Qt::AlignCenter);
  data_grid_->addWidget(fcolor_, 3, 2, Qt::AlignCenter);
  data_grid_->setContentsMargins(0, 0, 0, 0);
  data_grid_->setVerticalSpacing(10);
  data_grid_->setHorizontalSpacing(5);

  for (auto label : labels) {
    label->setAlignment(Qt::AlignCenter);
    if (label != lvertex_ && label != lfacet_) {
      label->setFixedWidth(110);
      label->setStyleSheet(border_font_up);
    } else {
      label->setStyleSheet(label_font_up);
    }
  }

  for (auto name : QStringList{"□", "○", "none"}) {
    vtype_->addItem(name);
  }

  for (auto name : QStringList{"──", "----", "none"}) {
    ftype_->addItem(name);
  }

  vtype_->setCurrentIndex(static_cast<int>(Data::data().vertex_type));
  ftype_->setCurrentIndex(static_cast<int>(Data::data().facet_type));

  vsize_->setMinimum(1);
  vsize_->setMaximum(10);
  vsize_->setValue(Data::data().vertex_size);
  fsize_->setMinimum(1);
  fsize_->setMaximum(10);
  fsize_->setValue(Data::data().facet_size);

  vtype_->setFixedSize(70, 35);
  vsize_->setFixedSize(70, 35);
  vcolor_->setFixedSize(70, 35);
  ftype_->setFixedSize(70, 35);
  fsize_->setFixedSize(70, 35);
  fcolor_->setFixedSize(70, 35);

  vtype_->setStyleSheet(Style::kComboBoxStyle);
  vsize_->setStyleSheet(Style::kSpinBoxStyle);
  ftype_->setStyleSheet(Style::kComboBoxStyle);
  fsize_->setStyleSheet(Style::kSpinBoxStyle);

  connect(vtype_, &QComboBox::currentIndexChanged, this,
          &ObjectData::onDataChanged);
  connect(ftype_, &QComboBox::currentIndexChanged, this,
          &ObjectData::onDataChanged);
  connect(vcolor_, &ColorButton::colorChanged, this,
          &ObjectData::onDataChanged);
  connect(fcolor_, &ColorButton::colorChanged, this,
          &ObjectData::onDataChanged);
  connect(vsize_, &QSpinBox::valueChanged, this, &ObjectData::onDataChanged);
  connect(fsize_, &QSpinBox::valueChanged, this, &ObjectData::onDataChanged);
}

void ObjectData::onDataChanged(int value) {
  (void)value;
  emit dataChanged();
}

void ObjectData::recordData() {
  Data &data{Data::data()};

  if (vtype_->currentIndex() == 0) {
    data.vertex_type = VertexType::Square;
  } else if (vtype_->currentIndex() == 1) {
    data.vertex_type = VertexType::Circle;
  } else {
    data.vertex_type = VertexType::None;
  }

  if (ftype_->currentIndex() == 0) {
    data.facet_type = FacetType::Solid;
  } else if (ftype_->currentIndex() == 1) {
    data.facet_type = FacetType::Dotted;
  } else {
    data.facet_type = FacetType::None;
  }

  data.vertex_size = vsize_->value();
  data.facet_size = fsize_->value();
  data.vertex_color = vcolor_->getColor();
  data.facet_color = fcolor_->getColor();
}

}  // namespace s21
