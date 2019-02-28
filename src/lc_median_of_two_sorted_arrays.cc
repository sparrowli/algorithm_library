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


/*
public String longestPalindrome(String s) {
    if (s == null || s.length() < 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = Math.max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substring(start, end + 1);
}

private int expandAroundCenter(String s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
        L--;
        R++;
    }
    return R - L - 1;
}



class Solution {
    public boolean isMatch(String text, String pattern) {
        if (pattern.isEmpty()) return text.isEmpty();
        boolean first_match = (!text.isEmpty() &&
                               (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '.'));

        if (pattern.length() >= 2 && pattern.charAt(1) == '*'){
            return (isMatch(text, pattern.substring(2)) ||
                    (first_match && isMatch(text.substring(1), pattern)));
        } else {
            return first_match && isMatch(text.substring(1), pattern.substring(1));
        }
    }
}

enum Result {
    TRUE, FALSE
}

class Solution {
    Result[][] memo;

    public boolean isMatch(String text, String pattern) {
        memo = new Result[text.length() + 1][pattern.length() + 1];
        return dp(0, 0, text, pattern);
    }

    public boolean dp(int i, int j, String text, String pattern) {
        if (memo[i][j] != null) {
            return memo[i][j] == Result.TRUE;
        }
        boolean ans;
        if (j == pattern.length()){
            ans = i == text.length();
        } else{
            boolean first_match = (i < text.length() &&
                                   (pattern.charAt(j) == text.charAt(i) ||
                                    pattern.charAt(j) == '.'));

            if (j + 1 < pattern.length() && pattern.charAt(j+1) == '*'){
                ans = (dp(i, j+2, text, pattern) ||
                       first_match && dp(i+1, j, text, pattern));
            } else {
                ans = first_match && dp(i+1, j+1, text, pattern);
            }
        }
        memo[i][j] = ans ? Result.TRUE : Result.FALSE;
        return ans;
    }
}

class Solution {
    public boolean isMatch(String text, String pattern) {
        boolean[][] dp = new boolean[text.length() + 1][pattern.length() + 1];
        dp[text.length()][pattern.length()] = true;

        for (int i = text.length(); i >= 0; i--){
            for (int j = pattern.length() - 1; j >= 0; j--){
                boolean first_match = (i < text.length() &&
                                       (pattern.charAt(j) == text.charAt(i) ||
                                        pattern.charAt(j) == '.'));
                if (j + 1 < pattern.length() && pattern.charAt(j+1) == '*'){
                    dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
                } else {
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
}
*/