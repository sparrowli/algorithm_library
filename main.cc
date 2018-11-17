/*
 *  Copyright (c) 2018 sparrowli. All Rights Reserved.
 */
#include <iostream>
#include <vector>

#include "src/output_rate_calculator.h"

int main() {
  std::vector<int> sample_rates;
  sample_rates.push_back(8000);
  sample_rates.push_back(16000);

  std::vector<int>::iterator result;

  AudioMixer::DefaultOutputRateCalculator  rate_calculator;
  int prefer_rate = rate_calculator.CalculateOutputRate(sample_rates);

  std::cout << "prefer rate = "<< prefer_rate << '\n';
  return 0;
}
