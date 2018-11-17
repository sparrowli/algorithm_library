/*
 *  Copyright (c) 2018 sparrowli. All Rights Reserved.
 */

#include <iostream>
#include <vector>
#include "src/output_rate_calculator.h"
#include "gtest/gtest.h"

namespace {

class OutputRateCalculatorSpec : public testing::Test {
 protected:
  AudioMixer::DefaultOutputRateCalculator rate_calculator_;
  std::vector<int> sample_rates_;
};

TEST_F(OutputRateCalculatorSpec, empty) {
  EXPECT_EQ(0u, sample_rates_.size());
  EXPECT_EQ(48000, rate_calculator_.CalculateOutputRate(sample_rates_));
}

TEST_F(OutputRateCalculatorSpec, norrowband) {
  sample_rates_.push_back(8000);
  EXPECT_EQ(1u, sample_rates_.size());
  EXPECT_EQ(8000, rate_calculator_.CalculateOutputRate(sample_rates_));
}

TEST_F(OutputRateCalculatorSpec, superband) {
  sample_rates_.push_back(8000);
  sample_rates_.push_back(32000);
  EXPECT_EQ(2u, sample_rates_.size());
  EXPECT_EQ(32000, rate_calculator_.CalculateOutputRate(sample_rates_));
}

TEST_F(OutputRateCalculatorSpec, fullband) {
  sample_rates_.push_back(48000);
  EXPECT_EQ(48000, rate_calculator_.CalculateOutputRate(sample_rates_));
}

TEST_F(OutputRateCalculatorSpec, BeyondBand) {
  sample_rates_.push_back(48001);
  EXPECT_EQ(1u, sample_rates_.size());
  EXPECT_EQ(-1, rate_calculator_.CalculateOutputRate(sample_rates_));
}

}  // namespace
