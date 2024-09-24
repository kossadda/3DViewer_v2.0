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
                                                 const float max)
    : min_{min}, max_{max} {}

}  // namespace s21
