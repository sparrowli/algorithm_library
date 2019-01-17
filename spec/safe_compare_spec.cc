#include "src/safe_compare.h"

#include "gtest/gtest.h"

namespace rtc {

namespace {

constexpr std::uintmax_t umax = std::numeric_limits<std::uintmax_t>::max();
constexpr std::intmax_t imin = std::numeric_limits<std::intmax_t>::min();
constexpr std::intmax_t m1 = -1;

// m1 and umax 
static_assert(static_cast<std::uintmax_t>(m1) == umax, "");
static_assert(m1 == static_cast<std::intmax_t>(umax), "");

static const std::pair<int, int> p1(1, 1);
static const std::pair<int, int> p2(1, 2);
}

TEST(SafeCmpSpec, Eq) {
  static_assert(!SafeEq(-1, 2), "");

  EXPECT_TRUE(SafeEq(p1, p1));

  EXPECT_FALSE(SafeEq(p1, p2));
  EXPECT_FALSE(SafeEq(p2, p1));

  EXPECT_TRUE(SafeEq(p2, p2));
}
}  // namespace rtc