#include "src/lc_regular_expression_matching.h"
#include <iostream>

RegularExpressionMatchingSolution::~RegularExpressionMatchingSolution() {
  if (memo_ != nullptr) {
    FreeMemo();
  }
}

void RegularExpressionMatchingSolution::FreeMemo() {
  for (int i = 0; i < row_; ++i) {
  	delete [] memo_[i];
    memo_[i] = nullptr;
  }
  memo_ = nullptr;
}

bool RegularExpressionMatchingSolution::IsMatch(std::string str, std::string pattern) {
  
  if (pattern.empty()) {
    return str.empty();
  }

  int input_len = str.size();
  int pattern_len = pattern.size();

  bool first_match = !str.empty() && (str[0] == pattern[0] || pattern[0] == '.');

  if (pattern_len >= 2 && pattern[1] == '*') {
    return (first_match && IsMatch(str.substr(1), pattern)) || (IsMatch(str, pattern.substr(2)));
  }
  return first_match && IsMatch(str.substr(1), pattern.substr(1));
}

bool RegularExpressionMatchingSolution::dp(int i, int j, std::string s, std::string p) {

  int s_len = s.size();
  int p_len = p.size();

  bool ans;

  if (j == p_len) {
    ans = i == s_len;
  } else {
    bool first_match = (i < s_len) && (p[j] == s[i] || p[j] == '.');

    if (j + 1 < p_len && p[j + 1] == '*') {
      ans = dp(i, j + 2, s, p) || (first_match && dp(i + 1, j, s, p));
    } else {
      ans = first_match && dp(i+1, j+1, s, p);
    }
  }

  memo_[i][j] = ans;
  return ans;
}

bool RegularExpressionMatchingSolution::IsMatchWithDP_Top_Down(std::string s, std::string p) {
  int s_len = s.size();
  int p_len = p.size();
  int i = 0;
  int j = 0;

  memo_ = new bool*[s_len + 1];
  for (i = 0; i < s_len + 1; ++i) {
    memo_[i] = new bool[p_len + 1];
  }
  row_ = s_len + 1;
  col_ = p_len + 1;

  bool ans = dp(0, 0, s, p);
  PrintMemo();

  return ans;
}

void RegularExpressionMatchingSolution::PrintMemo() const {
  for (int i = 0; i < row_; ++i) {
    for (int j = 0; j < col_; ++j) {
      std::cout<<" "<<memo_[i][j];
    }
    std::cout<<std::endl;
  }
}

bool RegularExpressionMatchingSolution::IsMatchWithDP(std::string s, std::string p) {
  int s_len = s.size();
  int p_len = p.size();

  if (p.empty()) {
    return s.empty();
  }

  bool dp[s_len + 1][p_len + 1];
  dp[s_len][p_len] = true;

  for (int i = s_len - 1; i >= 0; --i) {
    for (int j = p_len - 1; j >= 0; --j) {
      int first_match = i < s_len && (s[i] == p[j] || p[j] == '.');

      if (j + 1 < p_len && p[j + 1] == '*') {
        dp[i][j] = dp[i][j+2] || (first_match && dp[i+1][j]);
      } else {
        dp[i][j] = first_match && dp[i+1][j+1];
      }
    }
  }

  return dp[0][0];
}