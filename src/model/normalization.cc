/**
 * @file normalization.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/normalization.h"

namespace s21 {
NormalizationParameters::NormalizationParameters(const float min,
                                                 const float max,
                                                 const float dx_step,
                                                 const float dy_step)
    : min_{min}, max_{max}, dx_step_{dx_step}, dy_step_{dy_step} {}

}  // namespace s21
