#include "src/base_algorithm.h"

#include <math.h>

#include "src/checks.h"

int SumOfTwoNumber(int added, int augend) {
  return added + augend;
}

int MaximumOfThreeNumber(int a, int b, int c) {
  int max = 0;
  if (a > b) {
    if (a > c) {
      max = a;
    } else {
      max = c;
    }
  } else {
    if (b > c) {
      max = b;
    } else {
      max = c;
    }
  }

  return max;
}

// ToDo: return two-tuples
int RootOfQuadraticEquation(int a, int b, int c) {
  int discriminant = 0;
  int root_1 = 0;
  int root_2 = 0;

  discriminant = b * b - 4 * a * c;

  if (discriminant >= 0) {
    root_1 = -b / 2 * a + sqrt(discriminant) / 2 * a;
    root_2 = -b / 2 * a - sqrt(discriminant) / 2 * a;
  } else {
  	// ToDo
  }

  return root_1;
}

int Factorial(int n) {
  int factorial = 1;
  int i = 1;

  while (i <= n) {
  	factorial *= i;
    ++i;
  }

  return factorial;
}

bool IsPrime(int n) {
  if (n <= 1) {
    return false;
  }

  if (n % 2 == 0) return n == 2;

  for (int i = 3; ; i += 2) {
    if (i > n / i) break;

    if ( n % i == 0) return false;
  }

  return true;
}

bool IsOneOfFibonacci(int n) {
  int first_iterm = 0;
  int second_iterm = 1;

  if (1 >= n) return (n == 1 || n == 0);

  int temp = 0;

  while (second_iterm < n) {
    temp = second_iterm;

    second_iterm = second_iterm + first_iterm;

    first_iterm = temp;

    if (second_iterm == n) return true;
  }

  return false;
}



int SumOfNaturalNumbersUsingRecursion(int natural_number) {
  RTC_CHECK_GE(natural_number, 0);
  if (natural_number != 0) {
    return natural_number + SumOfNaturalNumbersUsingRecursion(natural_number - 1);
  } else {
    return natural_number;
  }
}

void InsertionSortingForArrayInAscendingOrder(int *unordered_array, size_t len) {
  int temp = 0;
  // size_t is the unsigned integer type of the result of operator .
  int j = 0;

  for (size_t i = 1; i < len; i++) {
    temp = unordered_array[i];
    j = i - 1;

    while (temp < unordered_array[j] && j >= 0) {
      unordered_array[j + 1] = unordered_array[j];
      --j;
    }

    unordered_array[j + 1] = temp;

  }

  return;
}