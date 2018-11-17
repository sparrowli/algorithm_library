/*
 *  Copyright (c) 2018 sparrowli. All Rights Reserved.
 */

#ifndef SRC_OUTPUT_RATE_CALCULATOR_H_
#define SRC_OUTPUT_RATE_CALCULATOR_H_

#include <vector>

namespace AudioMixer {

template<class ForwardIt>
ForwardIt max_element(ForwardIt first, ForwardIt last) {
    if (first == last) return last;

    ForwardIt largest = first;
    ++first;
    for (; first != last; ++first) {
        if (*largest < *first) {
            largest = first;
        }
    }
    return largest;
}

template<class ForwardIt, class T>
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value) {
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first, last);

    while (count > 0) {
        it = first;
        step = count / 2;
        std::advance(it, step);
        if (*it < value) {
            first = ++it;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return first;
}

class DefaultOutputRateCalculator {
 public:
  static const int kDefaultFrequency = 48000;

  // Produces the least native rate greater or equal to the preferred
  // sample rates. A native rate is one in
  // AudioProcessing::NativeRate. If |preferred_sample_rates| is
  // empty, returns |kDefaultFrequency|.
  int CalculateOutputRate(
      const std::vector<int>& preferred_sample_rates);
  ~DefaultOutputRateCalculator() {}
};

}  // namespace AudioMixer

#endif  // SRC_OUTPUT_RATE_CALCULATOR_H_
