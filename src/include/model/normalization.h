/**
 * @file normalization.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_NORMALIZATION_H_
#define SRC_INCLUDE_MODEL_NORMALIZATION_H_

namespace s21 {
struct NormalizationParameters {
  NormalizationParameters() noexcept = default;
  NormalizationParameters(const float min, const float max);

  float min_{};
  float max_{};
  float dx_step_{};
  float dy_step_{};
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_NORMALIZATION_H_
