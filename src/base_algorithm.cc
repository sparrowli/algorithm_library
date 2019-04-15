#include "src/base_algorithm.h"

#include <math.h>
#include <limits.h>
#include <vector>

#include "src/checks.h"

std::string TwoLargerNumsMultiply(std::string s1, std::string s2) {
  size_t len1 = s1.length();
  size_t len2 = s2.length();

  if (len1 == 0 || len2 == 0) {
    return "0";
  }

  size_t carry = 0;

  std::vector<int> result(len1 + len2, 0);

  int digit_1 = 0;
  int digit_2 = 0;

  int index_1 = 0;
  int index_2 = 0;

  int pos_1 = 0;
  int pos_2 = 0;

  int sum = 0;

  for (index_1 = len1 - 1; index_1 >= 0; --index_1) {

    digit_1 = s1[index_1] - '0';

    carry = 0;
    pos_2 = 0;

    for (index_2 = len2 -1; index_2 >= 0; --index_2) {

      digit_2 = s2[index_2] - '0';

      sum = digit_1 * digit_2 + result[pos_1 + pos_2] + carry;

      result[pos_1 + pos_2] = sum % 10;

      carry = sum / 10;

      ++pos_2;
    }

    if (carry) {
      result[pos_1 + pos_2] += carry;
    }
    ++pos_1;
  }



  int leading_zero = result.size() - 1;
  while (leading_zero >= 0 && result[leading_zero] == 0) {
    leading_zero--;
  }

  if (leading_zero == -1) {
    return "0";
  }

  std::string s = "";
  while (leading_zero >= 0) {
    s += std::to_string(result[leading_zero--]);
  }
  return s;
}

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

int* SelectionSortingForArrayInAscendingOrder(int *unordered_data, size_t len) {
  if (len < 2) {
    return unordered_data;
  }

  int temp = 0;
  int j = 0;

  for (size_t i = 0; i < len - 1; ++i) {
    temp = unordered_data[i];
    j = i + 1;

    while ( j < len) {
      

      if (temp > unordered_data[j]) {
        unordered_data[i] = unordered_data[j];
        unordered_data[j] = temp;

        temp = unordered_data[i];
      }


      ++j;
    }

  }

  return unordered_data;
}

int* HeapSortingForArrayInAscendingOrder(int *unordered_data, size_t len) {
  BuildHeap(unordered_data, len);

  for (int i = len - 1; i >= 0; --i) {
    std::swap(unordered_data[0], unordered_data[i]);

    Heapify(unordered_data, i, 0);
  }

  return unordered_data;
}

void Heapify(int array[], size_t N, size_t index) {
  size_t largest = index;
  size_t l = 2 * index + 1;
  size_t r = 2 * index + 2;

  if (l < N && array[l] > array[largest]) {
    largest = l;
  }

  if (r < N && array[r] > array[largest]) {
    largest = r;
  }

  if (index != largest) {
    std::swap(array[index], array[largest]);

    Heapify(array, N, largest);
  }
}

void BuildHeap(int array[], size_t N) {
  for (int i = 2 * N - 1; i >= 0; --i) {
    Heapify(array, N, i);
  }
}

void Merge(int data[], size_t p, size_t q, size_t r) {
  // create two array from |data[]|
  size_t n1 = q - p + 1;
  size_t n2 = r - (q + 1) + 1;

  int L[n1], M[n2];

  for (int i = 0; i < n1; ++i) {
    L[i] = data[p + i];
  }

  for (int j = 0; j < n2; ++j) {
    M[j] = data[q + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = p;

  while (i < n1 && j < n2) {

    if (L[i] <= M[j]) {
      data[k] = L[i];
      ++i;
    } else {
      data[k] = M[j];
      ++j;
    }

    ++k;
  }

  while (i < n1) {
    data[k] = L[i];
    ++i;
    ++k;
  }

  while (j < n2) {
    data[k] = M[j];
    ++j;
    ++k;
  }

}

void MergeSort(int data[], size_t p, size_t r) {
  if (p >= r)
    return;

  int q = (p + r) / 2;

  MergeSort(data, p, q);
  MergeSort(data, q + 1, r);

  Merge(data, p, q, r);
}

void BubbleSort(int data[], size_t N) {
  int temp = 0;
  for (int step = 0; step < N - 1; ++step) {
    for (int i = 0; i < N - step - 1; ++i) {

      if (data[i] > data[i + 1]) {
        temp = data[i];
        data[i] = data[i + 1];
        data[i + 1] = temp;
      }
    }
  }
}



// p.862

// power of 2 that is greater than or equal argument
unsigned long nextpow2(unsigned long X)
{
    unsigned long C = 1;
    while( (C < ULONG_MAX) && (C < X) )
        C <<= 1;

    return C;
}

// whether is the argument the power of 2
int ispow2(unsigned long X)
{
    unsigned long C = 1;
    while( (C < ULONG_MAX) && (C < X) )
        C <<= 1;
        
    return (C == X);
}

float interpolate (float    freq, 
                   double   filter_curve_db [][2],
                   int      number_of_points) {
    double  result;
    int     i;
    double  freqLow, freqHigh;
    double  curveLow, curveHigh;
    
    if (freq <= filter_curve_db [0][0]) {
        freqLow = filter_curve_db [0][0];
        curveLow = filter_curve_db [0][1];
        freqHigh = filter_curve_db [1][0];
        curveHigh = filter_curve_db [1][1];

        result = ((freq - freqLow) * curveHigh + (freqHigh - freq) * curveLow)/ (freqHigh - freqLow);
    
        return (float) result;
    }

    if (freq >= filter_curve_db [number_of_points-1][0]) {
        freqLow = filter_curve_db [number_of_points-2][0];
        curveLow = filter_curve_db [number_of_points-2][1];
        freqHigh = filter_curve_db [number_of_points-1][0];
        curveHigh = filter_curve_db [number_of_points-1][1];

        result = ((freq - freqLow) * curveHigh + (freqHigh - freq) * curveLow)/ (freqHigh - freqLow);
    
        return (float) result;
    }
        
    i = 1;
    freqHigh = filter_curve_db [i][0];
    while (freqHigh < freq) {
        i++;
        freqHigh = filter_curve_db [i][0];    
    }
    curveHigh = filter_curve_db [i][1];

    freqLow = filter_curve_db [i-1][0];
    curveLow = filter_curve_db [i-1][1];

    result = ((freq - freqLow) * curveHigh + (freqHigh - freq) * curveLow)/ (freqHigh - freqLow);

    return (float) result;
}





