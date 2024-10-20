/**
 * @file base_widget.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief Implementation file for the BaseWidget class
 * @version 1.0
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/base_widget.h"

namespace s21 {

/**
 * @brief Construct a new BaseWidget object.
 *
 * @param title Optional pointer to a QLabel for the widget's title.
 *              If not provided, the title will be set to nullptr.
 */
BaseWidget::BaseWidget(QLabel *title) : QWidget{} {
  allocateMemory(title);
  initView();
}

/**
 * @brief Allocate memory for the widget's components.
 *
 * @param title Pointer to a QLabel for the widget's title.
 *
 * This method is virtual and can be overridden by derived classes to customize
 * the memory allocation process.
 */
void BaseWidget::allocateMemory(QLabel *title) {
  grid_ = new QGridLayout;
  frame_grid_ = new QGridLayout;
  frame_ = new QFrame;
  title_ = title;
}

/**
 * @brief Initialize the view components of the widget.
 *
 * This method is virtual and can be overridden by derived classes to
 * customize the view initialization process.
 */
void BaseWidget::initView() {
  QGridLayout *title_grid{new QGridLayout};
  setLayout(frame_grid_);
  frame_grid_->setContentsMargins(1, 1, 1, 1);

  frame_grid_->addWidget(frame_);
  frame_->setLayout(grid_);

  grid_->setVerticalSpacing(4);
  grid_->addLayout(title_grid, 0, 0, Qt::AlignTop);

  if (title_) {
    setIcon(40, 25);

    title_grid->addWidget(icon_, 0, 0);
    title_grid->addWidget(title_, 0, 1, Qt::AlignCenter);
    title_->setStyleSheet(QString{Style::kLabelStyle}.replace("14px", "15px"));
  }

  setStyleSheet(Style::kWindowStyle);
  frame_->setStyleSheet(Style::kFrameStyle);
}

/**
 * @brief Get the title of the widget.
 *
 * @return QString The title of the widget.
 */
QString BaseWidget::title() { return (title_) ? title_->text() : QString{}; }

/**
 * @brief Set an icon for the widget.
 *
 * @param w Width of the icon.
 * @param h Height of the icon.
 */
void BaseWidget::setIcon(int w, int h) {
  icon_ = new QLabel;
  icon_->setStyleSheet(Style::kLabelStyle);
  icon_->setFixedSize(w, h);
  icon_->setScaledContents(true);
}

}  // namespace s21
