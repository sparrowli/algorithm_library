#include "src/lc_regular_expression_matching.h"

#include "spec/lc_clock.h"
#include "gtest/gtest.h"

class RegularExpressionMatchingSpec : public QuickTest {
 protected:
  virtual void SetUp() {
    QuickTest::SetUp();
  }

  virtual void TearDown() {
    QuickTest::TearDown();
  }

  RegularExpressionMatchingSolution s;
};

TEST_F(RegularExpressionMatchingSpec, IsMatchEmptyInputAndPattern) {
  std::string str = "";
  std::string pattern = "";

  EXPECT_TRUE(s.IsMatch(str, pattern));
  EXPECT_TRUE(s.IsMatchWithDP_Top_Down(str, pattern));
  EXPECT_TRUE(s.IsMatchWithDP(str, pattern));
}

TEST_F(RegularExpressionMatchingSpec, IsMatchEmptyPatternButInput) {
  std::string str = "a";
  std::string pattern = "";

  EXPECT_FALSE(s.IsMatch(str, pattern));
  EXPECT_FALSE(s.IsMatchWithDP_Top_Down(str, pattern));
  EXPECT_FALSE(s.IsMatchWithDP(str, pattern));
}

TEST_F(RegularExpressionMatchingSpec, IsMatchEmptyInputButPattern) {
  std::string str = "";
  std::string pattern = "a";

  EXPECT_FALSE(s.IsMatch(str, pattern));
  EXPECT_FALSE(s.IsMatchWithDP_Top_Down(str, pattern));
  // EXPECT_FALSE(s.IsMatchWithDP(str, pattern));
}

TEST_F(RegularExpressionMatchingSpec, IsMatchWithoutWildcard) {
  std::string str = "aa";
  std::string pattern = "a";

  EXPECT_FALSE(s.IsMatch(str, pattern));
  EXPECT_FALSE(s.IsMatchWithDP_Top_Down(str, pattern));
  // EXPECT_FALSE(s.IsMatchWithDP(str, pattern));
}

TEST_F(RegularExpressionMatchingSpec, IsMatchWithDot) {
  std::string str = "aa";
  std::string pattern = ".a";

  EXPECT_TRUE(s.IsMatch(str, pattern));
  EXPECT_TRUE(s.IsMatchWithDP_Top_Down(str, pattern));

  // EXPECT_TRUE(s.IsMatchWithDP(str, pattern));
}

TEST_F(RegularExpressionMatchingSpec, IsMatchWithAsterisk) {
  std::string str = "aa";
  std::string pattern = "a*";

  EXPECT_TRUE(s.IsMatch(str, pattern));
  
  EXPECT_TRUE(s.IsMatchWithDP_Top_Down(str, pattern));
  // EXPECT_TRUE(s.IsMatchWithDP(str, pattern));
}

TEST_F(RegularExpressionMatchingSpec, IsMatchWithDotAndAsterisk) {
  std::string str = "ab";
  std::string pattern = ".*";

  EXPECT_TRUE(s.IsMatch(str, pattern));
  // EXPECT_TRUE(s.IsMatchWithDP(str, pattern));
}

TEST_F(RegularExpressionMatchingSpec, IsMatchWithMultiAsterisk) {
  std::string str = "aab";
  std::string pattern = "c*a*b*";

  EXPECT_TRUE(s.IsMatch(str, pattern));
  // EXPECT_TRUE(s.IsMatchWithDP(str, pattern));
}

TEST_F(RegularExpressionMatchingSpec, IsMatchWithLongAsteriskString) {
  std::string str = "mississippi";
  std::string pattern = "mis*is*p*.";

  EXPECT_FALSE(s.IsMatch(str, pattern));
  // EXPECT_FALSE(s.IsMatchWithDP(str, pattern));
}