/**
 * @file style.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/style.h"

const QString Style::kWindowStyle =
    "QWidget {"
    "  background: rgba(10, 10, 10, 0.7);"
    "}";

const QString Style::kWindowTranparentStyle =
    "QWidget {"
    "  background: rgba(0, 0, 0, 0.0);"
    "}";

const QString Style::kFrameStyle =
    "QFrame {"
    "  background: rgba(45, 45, 45, 0.5);"
    "  border-radius: 10px;"
    "  border: 1px solid #5e0107;"
    "}";

const QString Style::kSliderStyle =
    "QSlider {"
    "  background-color: rgba(0, 0, 0, 0.0);"
    "}"
    "QSlider::groove:horizontal {"
    "  border: 1px solid #999999;"
    "  height: 8px;"
    "  background-color: rgb(31, 14, 65);"
    "  margin: 2px 0;"
    "}"
    "QSlider::handle:horizontal {"
    "  background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, "
    "  stop:1 #8f8f8f);"
    "  border: 1px solid #5c5c5c;"
    "  width: 18px;"
    "  margin: -2px 0;"
    "  border-radius: 2px;"
    "}"
    "QSlider::add-page:horizontal {"
    "  background: rgb(255, 255, 255);"
    "}"
    "QSlider::sub-page:horizontal {"
    "  background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #6c6c6c, "
    "  stop:1 #989898);"
    "}";

const QString Style::kLabelStyle =
    "background-color: rgba(0, 0, 0, 0.0);"
    "padding-right: 15px;"
    "color: rgb(255, 255, 255);"
    "border: none;"
    "font-size: 14px;";

const QString Style::kSpinBoxStyle =
    "QSpinBox {"
    "  background-color: rgb(47, 47, 47);"
    "  border: 1px solid #636363;"
    "  padding: 1px 0px 1px 10px;"
    "  border-radius: 10px;"
    "  color: rgb(255, 255, 255);"
    "}"
    "QSpinBox::down-button {"
    "  image: url(:down_arrow_white.png);"
    "  margin-right: 2px;"
    "}"
    "QSpinBox::up-button {"
    "  image: url(:up_arrow_white.png);"
    "  margin-right: 2px;"
    "}";

const QString Style::kButtonStyle =
    "QPushButton:pressed {"
    "  background-color: rgb(47, 47, 47);"
    "}"
    "QPushButton {"
    "  background-color: #400105;"
    "  color: rgb(255, 255, 255);"
    "  border-radius: 10px;"
    "  border: 1px solid #636363;"
    "  font-size: 14px;"
    "}";

const QString Style::kLineEditStyle =
    "border-radius: 10px;"
    "background-color: rgb(47, 47, 47);"
    "border: 1px solid #5e0107;"
    "font-size: 17px;"
    "padding-left: 16px;"
    "color: rgb(255, 255, 255);";

const QString Style::kComboBoxStyle =
    "QComboBox {"
    "  subcontrol-origin: padding;"
    "  subcontrol-position: top right;"
    "  selection-background-color: transparent;"
    "  selection-color: #bd020e;"
    "  background-color: rgb(47, 47, 47);"
    "  font-size: 14px;"
    "  color: rgb(255, 255, 255);"
    "  border: 1px solid #636363;"
    "  border-radius: 10px;"
    "  padding: 1px 0px 1px 10px;"
    "}"
    "QComboBox::drop-down {"
    "  image: url(:down_arrow_white.png);"
    "  width: 13px;"
    "  height: 13px;"
    "  margin-top: 12px;"
    "  margin-right: 2px;"
    "}";
