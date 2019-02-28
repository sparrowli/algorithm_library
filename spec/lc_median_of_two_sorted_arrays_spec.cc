#include "src/lc_median_of_two_sorted_arrays.h"

#include "spec/lc_clock.h"
#include "gtest/gtest.h"

#include <math.h>

class MedianSolutionSpec : public QuickTest {
 protected:
  virtual void SetUp() {
    QuickTest::SetUp();
  }

  virtual void TearDown() {
    QuickTest::TearDown();
  }

  MedianSolution s;
};

// What's the definition of median?
// 2nd point: merge two sorted arrays to one sorted array? merge sort

TEST_F(MedianSolutionSpec, GetMedianWithOddElements) {
  std::vector<int> a1 = {1, 3};
  std::vector<int> a2 = {2};

  double expect_val = 2.0;
  double actual_val = s.FindMedianSortedArrays(a1, a2);

  EXPECT_EQ(expect_val, actual_val);
}

TEST_F(MedianSolutionSpec, GetMedianWithEvenElements) {
  std::vector<int> a1 = {1, 5};
  std::vector<int> a2 = {3, 6};

  // Test 2.*PI
  // double x = 2.*3.141592;
  // std::cout<<"2.*PI = "<<x<<std::endl;

  std::cout<<"pow(10.0, -20.0) = "<<pow(10.0, -20.0)<<std::endl;

  std::cout<<"log(e) = "<<log(2.7)<<std::endl;
  std::cout<<"log2(512) = "<<log(512.0) / log(2.0)<<std::endl;
  std::cout<<"freqs[0] = "<<133.3333<<std::endl;
  std::cout<<"freqs_step"<<66.66666666<<std::endl;
  std::cout<<"freqs[12] = "<<133.3333 + 12 * 66.66666666<<std::endl;
  double freqs_12 = (133.3333 + 12 * 66.66666666);
  std::cout<<"freqs[13] = "<<freqs_12*pow(1.0711703, 1)<<std::endl;
  std::cout<<"freqs[31] = "<<freqs_12*pow(1.0711703, 19)<<std::endl;
  std::cout<<"freqs[33] = "<<freqs_12*pow(1.0711703, 21)<<std::endl;

  double freqs_31 = freqs_12*pow(1.0711703, 19);
  double freqs_33 = freqs_12*pow(1.0711703, 21);
  double filtgain_0 = 2.0 / (66.66666666 * 2);
  double filtgain_31 = 2.0 / (freqs_33 - freqs_31);

  std::cout<<"freqs[31] = "<<freqs_31<<std::endl;
  std::cout<<"freqs[33] = "<<freqs_33<<std::endl;
  std::cout<<"filtgain[0] = "<<filtgain_31<<std::endl;
  std::cout<<"filtgain[31] = "<<filtgain_31<<std::endl;

  std::cout<<"fftfreq[0] = "<<0<<std::endl;
  std::cout<<"fftfreq[1] = "<<1.0 / 512 * 8000<<std::endl;
  std::cout<<"fftfreq[255] = "<<255.0 / 512 * 8000<<std::endl;

  double expect_val = 4.0;
  double actual_val = s.FindMedianSortedArrays(a1, a2);

  EXPECT_EQ(expect_val, actual_val);
}