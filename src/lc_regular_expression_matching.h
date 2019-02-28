#ifndef ALGORITHM_LIBRARY_SRC_LC_REGULAR_EXPRESSION_MATCHING_H_
#define ALGORITHM_LIBRARY_SRC_LC_REGULAR_EXPRESSION_MATCHING_H_

#include <string>

class RegularExpressionMatchingSolution {
 public:
  ~RegularExpressionMatchingSolution();
  bool IsMatch(std::string s, std::string p);
  bool IsMatchWithDP_Top_Down(std::string s, std::string p);

  bool IsMatchWithDP(std::string s, std::string p);

  void PrintMemo() const;
 private:
  bool dp(int i, int j, std::string s, std::string p);
  void FreeMemo();

  bool **memo_;
  int row_;
  int col_;
};
#endif  // ALGORITHM_LIBRARY_SRC_LC_REGULAR_EXPRESSION_MATCHING_H_