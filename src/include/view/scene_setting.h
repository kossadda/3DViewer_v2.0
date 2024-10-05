/**
 * @file scene_setting.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_SCENE_SETTING_H_
#define SRC_INCLUDE_VIEW_SCENE_SETTING_H_

#include "include/view/base_widget.h"

class SceneSetting : public BaseWidget {
 public:
  SceneSetting();
  ~SceneSetting();

 private:
  void allocateMemory();
  void initView();
};

#endif  // SRC_INCLUDE_VIEW_SCENE_SETTING_H_
