#include "src/base_algorithm.h"

//#include <math.h>

#include "gtest/gtest.h"

namespace {

TEST(TwoNumbersAddedSpec, integrate) {
  EXPECT_EQ(2, SumOfTwoNumber(1, 1));
  /*
  EXPECT_EQ(4, sizeof(int));
  EXPECT_EQ(4.29497e+09, pow(2, 32));

  EXPECT_EQ(pow(2, 32) + 1, SumOfTwoNumber(pow(2, 32), 1));
  */
}

TEST(MaximumOfThreeNumberSpec, integrate) {
  EXPECT_EQ(3, MaximumOfThreeNumber(1, 2, 3));
}

TEST(RootOfQuadraticEquationSpec, integrate) {
  EXPECT_EQ(2, RootOfQuadraticEquation(1, -4, 4));
}

TEST(FactorialSpec, Negative) {
  EXPECT_EQ(1, Factorial(-1));
  EXPECT_EQ(1, Factorial(-5));
  EXPECT_GT(Factorial(-1), 0);
}

// Tests factorial of 0.
TEST(FactorialSpec, Zero) {
  EXPECT_EQ(1, Factorial(0));
}

TEST(FactorialSpec, Positive) {
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(6, Factorial(3));
  EXPECT_EQ(40320, Factorial(8));
}

TEST(IsPrimeSpec, Negative) {

  EXPECT_FALSE(IsPrime(-1));
  EXPECT_FALSE(IsPrime(-2));
  EXPECT_FALSE(IsPrime(INT_MIN));
}

TEST(IsPrimeSpec, Positive) {
  EXPECT_FALSE(IsPrime(4));
  EXPECT_TRUE(IsPrime(5));
  EXPECT_FALSE(IsPrime(6));
  EXPECT_TRUE(IsPrime(23));
}

TEST(IsOneOfFibonacciSpec, Positive) {
  EXPECT_TRUE(IsOneOfFibonacci(2));
  EXPECT_TRUE(IsOneOfFibonacci(3));
  EXPECT_FALSE(IsOneOfFibonacci(4));
  EXPECT_TRUE(IsOneOfFibonacci(5));
}

TEST(IsOneOfFibonacciSpec, Negative) {
  EXPECT_FALSE(IsOneOfFibonacci(-1));
  EXPECT_FALSE(IsOneOfFibonacci(-19));
}

TEST(IsOneOfFibonacciSpec, trivial) {
  EXPECT_TRUE(IsOneOfFibonacci(0));
  EXPECT_TRUE(IsOneOfFibonacci(1));
}

TEST(RecurseSpec, FiniteRecursion) {
  // SumOfNaturalNumbersUsingRecursion(-1);              // test RTC_CHECK_GE
  EXPECT_EQ(0, SumOfNaturalNumbersUsingRecursion(0));
  EXPECT_EQ(15, SumOfNaturalNumbersUsingRecursion(5));
}

TEST(InsertionSortSpec, NoSorting) {
  int unordered_array[] = {1, 2};
  int ordered_array[] {1, 2};

  size_t N = sizeof(ordered_array) / sizeof(ordered_array[0]);
  EXPECT_EQ(2, N);
  
  InsertionSortingForArrayInAscendingOrder(unordered_array, N);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(ordered_array[i], unordered_array[i]);
  }
}

TEST(InsertionSortSpec, TwoElementSorting) {
  int unordered_array[] = {2, 1};
  int ordered_array[] = {1, 2};

  size_t N = sizeof(ordered_array) / sizeof(ordered_array[0]);
  EXPECT_EQ(2, N);
  
  InsertionSortingForArrayInAscendingOrder(unordered_array, N);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(ordered_array[i], unordered_array[i]);
  }
}

TEST(InsertionSortSpec, ThreeElementSorting) {
  int unordered_array[] = {1, 3, 2};
  int ordered_array[] = {1, 2, 3};

  size_t N = sizeof(ordered_array) / sizeof(ordered_array[0]);
  EXPECT_EQ(3, N);
  
  InsertionSortingForArrayInAscendingOrder(unordered_array, N);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(ordered_array[i], unordered_array[i]);
  }
}

TEST(InsertionSortSpec, InAscendingOrder) {
  int unordered_array[] = {3, 2, 1};
  int ordered_array[] = {1, 2, 3};

  size_t N = sizeof(ordered_array) / sizeof(ordered_array[0]);
  EXPECT_EQ(3, N);
  
  InsertionSortingForArrayInAscendingOrder(unordered_array, N);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(ordered_array[i], unordered_array[i]);
  }
}
}  // namespace
