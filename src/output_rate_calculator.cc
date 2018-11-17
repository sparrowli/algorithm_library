/*
 *  Copyright (c) 2018 sparrowli. All Rights Reserved.
 */

#include "src/output_rate_calculator.h"

namespace AudioMixer {


int DefaultOutputRateCalculator::CalculateOutputRate(
    const std::vector<int>& preferred_sample_rates) {

if (preferred_sample_rates.empty()) {
    return DefaultOutputRateCalculator::kDefaultFrequency;
  }

  const int maximal_frequency = *AudioMixer::max_element(
      preferred_sample_rates.begin(), preferred_sample_rates.end());

  if (8000 > maximal_frequency || 48000 < maximal_frequency) {
    printf("Not support this maximal_frequency [%d].\n", maximal_frequency);
    return -1;
  }

  static const int native_rates[] = { 8000, 16000, 32000, 48000 };

  int prefer_rate = -1;
  if ( std::end(native_rates) != AudioMixer::lower_bound(
    std::begin(native_rates), std::end(native_rates), maximal_frequency) ) {
    prefer_rate = *AudioMixer::lower_bound(
    std::begin(native_rates), std::end(native_rates), maximal_frequency);
  }

  return prefer_rate;
}

}  // namespace AudioMixer
