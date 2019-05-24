#include "src/base_algorithm.h"

#include <math.h>

#include "gtest/gtest.h"

namespace {

TEST(TwoLargerNumsMultiply, BothAreOneDigit) {
  EXPECT_EQ("1", TwoLargerNumsMultiply("1", "1"));

  EXPECT_EQ("0", TwoLargerNumsMultiply("1", "0"));

  EXPECT_EQ("10", TwoLargerNumsMultiply("2", "5"));

  EXPECT_EQ("213739916", TwoLargerNumsMultiply("4154", "51454"));

  EXPECT_EQ("41549622603955309777243716069997997007620439937711509062916", TwoLargerNumsMultiply("654154154151454545415415454", "63516561563156316545145146514654"));
}

TEST(GenerateParenthesesSpec, CheckValidationAndNIsOne) {
  std::vector<std::string> actual_res;
  actual_res = GenerateParenthesesByHand(0);
  EXPECT_EQ(1, actual_res.size());
  EXPECT_EQ("", actual_res[0]);

  actual_res = GenerateParenthesesByHand(1);
  EXPECT_EQ(1, actual_res.size());
  EXPECT_EQ("()1", actual_res[0]);

  actual_res = GenerateParenthesesByHand(2);
  EXPECT_EQ(2, actual_res.size());
  EXPECT_EQ("()()", actual_res[0]);
  EXPECT_EQ("(())", actual_res[1]);
}


TEST(GenerateParenthesesSpec, CheckValidationAndNIsOne) {
  std::vector<std::string> actual_res;
  actual_res = GenerateParentheses(0);
  EXPECT_EQ(1, actual_res.size());
  EXPECT_EQ("", actual_res[0]);

  actual_res = GenerateParentheses(1);
  EXPECT_EQ(1, actual_res.size());
  EXPECT_EQ("()1", actual_res[0]);

  actual_res = GenerateParentheses(2);
  EXPECT_EQ(2, actual_res.size());
  EXPECT_EQ("()()", actual_res[0]);
  EXPECT_EQ("(())", actual_res[1]);
}

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

// Spec selection sort algorithm
TEST(SelctionSortSpec, SortedArray) {
  int sorting_array[] = {1, 2};
  int ordered_array[] {1, 2};

  size_t N = sizeof(ordered_array) / sizeof(ordered_array[0]);
  EXPECT_EQ(2, N);
  
  int* sorted_data = SelectionSortingForArrayInAscendingOrder(sorting_array, N);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(ordered_array[i], sorted_data[i]);
  }
}

TEST(SelctionSortSpec, UnsortedArray) {
  int sorting_array[] = {2, 1};
  int ordered_array[] {1, 2};

  size_t N = sizeof(ordered_array) / sizeof(ordered_array[0]);
  EXPECT_EQ(2, N);
  
  int* sorted_data = SelectionSortingForArrayInAscendingOrder(sorting_array, N);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(ordered_array[i], sorted_data[i]);
  }
}

TEST(SelectionSortSpec, ThreeElementSorting) {
  int sorting_array[] = {1, 3, 2};
  int ordered_array[] = {1, 2, 3};

  size_t N = sizeof(ordered_array) / sizeof(ordered_array[0]);
  EXPECT_EQ(3, N);
  
  int* sorted_data = SelectionSortingForArrayInAscendingOrder(sorting_array, N);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(ordered_array[i], sorting_array[i]);
  }
}

TEST(SelectionSortSpec, WorstCaseForTenElementSorting) {
  int sorting_array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int ordered_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  size_t N = sizeof(ordered_array) / sizeof(ordered_array[0]);
  EXPECT_EQ(10, N);
  
  int* sorted_data = SelectionSortingForArrayInAscendingOrder(sorting_array, N);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(ordered_array[i], sorting_array[i]);
  }
}

TEST(HeapSortSpec, CaseForTenElementSorting) {
  int sorting_array[] = {10, 3, 76, 34, 23, 32};
  int ordered_array[] = {3, 10, 23, 32, 34, 76};

  size_t N = sizeof(ordered_array) / sizeof(ordered_array[0]);
  EXPECT_EQ(6, N);
  
  int* sorted_data = HeapSortingForArrayInAscendingOrder(sorting_array, N);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(ordered_array[i], sorting_array[i]);
  }
}

TEST(SWAPSpec, CaseForTwoNode) {
  int x = 1, y = 2;
  int array [] = { 3, 4};

  std::swap(x, y);
  EXPECT_EQ(1, y);
  EXPECT_EQ(2, x);

  std::swap(array[0], array[1]);
  EXPECT_EQ(3, array[1]);
  EXPECT_EQ(4, array[0]);
}

TEST(HeapifySpec, CaseForSecondLevel) {
  int tree[] = {1, 2, 3};
  int heapified_tree[] = {3, 2, 1};

  size_t N = sizeof(tree) / sizeof(tree[0]);

  Heapify(tree, N, 0);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(heapified_tree[i], tree[i]);
  }
}

TEST(HeapifySpec, CaseForThirdLevel) {
  int tree[] = {1, 7, 20, 6, 5, 2, 3};
  int heapified_tree[] = {20, 7, 3, 6, 5, 2, 1};

  size_t N = sizeof(tree) / sizeof(tree[0]);

  Heapify(tree, N, 0);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(heapified_tree[i], tree[i]);
  }

}

TEST(HeapifySpec, BuildMaxHeap) {
  int tree[] = {1, 12, 9, 5, 6, 10};
  int heapified_tree[] = {12, 6, 10, 5, 1, 9};

  size_t N = sizeof(tree) / sizeof(tree[0]);

  BuildHeap(tree, N);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(heapified_tree[i], tree[i]);
  }
}

TEST(MergeSortSpec, WorstCaseForTwoElements) {
  int data[] = {5, 1};
  int sorted_data[] = {1, 5};

  size_t N = sizeof(data) / sizeof(data[0]);

  MergeSort(data, 0, N - 1);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(sorted_data[i], data[i]);
  }

}

TEST(MergeSortSpec, WorstCaseForThreeElements) {
  int data[] = {7, 5, 1};
  int sorted_data[] = {1, 5, 7};

  size_t N = sizeof(data) / sizeof(data[0]);

  MergeSort(data, 0, N - 1);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(sorted_data[i], data[i]);
  }
}


TEST(MergeSortSpec, CaseForSixElements) {
  int data[] = {6, 5, 12, 10, 9, 1};
  int sorted_data[] = {1, 5, 6, 9, 10, 12};

  size_t N = sizeof(data) / sizeof(data[0]);

  MergeSort(data, 0, N - 1);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(sorted_data[i], data[i]);
  }
}

TEST(BubbleSortSpec, CaseForSixElements) {
  int data[] = {6, 5, 12, 10, 9, 1};
  int sorted_data[] = {1, 5, 6, 9, 10, 12};

  size_t N = sizeof(data) / sizeof(data[0]);

  BubbleSort(data, N);

  for (size_t i = 0; i < N; ++i) {
    EXPECT_EQ(sorted_data[i], data[i]);
  }

}

// p.862

double align_filter_dB [26] [2] = {{0.,-500},
                                 {50., -500},
                                 {100., -500},
                                 {125., -500},
                                 {160., -500},
                                 {200., -500},
                                 {250., -500},
                                 {300., -500},
                                 {350.,  0},
                                 {400.,  0},
                                 {500.,  0},
                                 {600.,  0},
                                 {630.,  0},
                                 {800.,  0},
                                 {1000., 0},
                                 {1250., 0},
                                 {1600., 0},
                                 {2000., 0},
                                 {2500., 0},
                                 {3000., 0},
                                 {3250., 0},
                                 {3500., -500},
                                 {4000., -500},
                                 {5000., -500},
                                 {6300., -500},
                                 {8000., -500}};

TEST(P862DSPSpec, PowerOfTwo) {
  EXPECT_EQ(4, nextpow2(3));
  EXPECT_EQ(5, nextpow2(5));
  EXPECT_EQ(5, nextpow2(9));
  EXPECT_EQ(pow(2, 17), nextpow2(69776));
  EXPECT_TRUE(ispow2(nextpow2(3) + 4));
  EXPECT_TRUE(ispow2(nextpow2(69776)));


  float overallGainFilter = 1.0;
  EXPECT_EQ(overallGainFilter, interpolate((float) 1000, align_filter_dB, 26));
}



}  // namespace
