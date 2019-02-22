#include "src/lc_median_of_two_sorted_arrays.h"

#include <iostream>

double MedianSolution::FindMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
  double median = 0.0;

  std::vector<int> A;
  std::vector<int> B;

  int m = nums1.size();
  int n = nums2.size();
  int temp = 0;

  int imin, imax, half_len;
  int i, j;

  if (n < m) {
    temp = m;
    m = n;
    n = temp;

    A = nums2;
    B = nums1;  
  } else {
    A = nums1;
    B = nums2;
  }

  imin = 0;
  imax = m;
  half_len = (m + n + 1) / 2;

  while (imin <= imax) {
    i = (imax + imin) / 2;
    j = half_len - i;

    if (i < imax && B[j - 1] > A[i]) {
      imin = i + 1;
    } else if (i > imin && A[i - 1] > B[j]) {
      imax = i - 1;
    } else {

      int max_left = 0;

      if (i == 0) {
        max_left = B[j - 1];
      } else if (j == 0) {
        max_left = A[i - 1];
      } else {
        max_left = std::max(A[i - 1], B[i - 1]);
      }

      if ((m + n) % 2 == 1) {
        return max_left;
      }

      int min_right = 0;
      if (i == m) {
        min_right = B[j];
      } else if (j == n) {
        min_right = A[i];
      } else {
        min_right = std::min(A[i], B[j]);
      }

      return (max_left + min_right) / 2.0;

    }
  }

  return median;
}