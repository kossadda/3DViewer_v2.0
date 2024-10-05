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
    "  background-color: rgb(50, 50, 50);"
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
    "font-size: 12px;";

const QString Style::kSpinBoxStyle =
    "background-color: rgba(15, 15, 15, 0.5);"
    "color: rgb(255, 255, 255)";
