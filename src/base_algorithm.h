#ifndef ALGORITHM_LIBRARY_SRC_BASE_ALGORITHM_H_
#define ALGORITHM_LIBRARY_SRC_BASE_ALGORITHM_H_

#include <cstddef>
#include <string>

std::string TwoLargerNumsMultiply(std::string s1, std::string s2);

int SumOfTwoNumber(int added, int augend);

int MaximumOfThreeNumber(int a, int b, int c);

int RootOfQuadraticEquation(int a, int b, int c);

int Factorial(int n);

bool IsPrime(int n);

bool IsOneOfFibonacci(int n);

int SumOfNaturalNumbersUsingRecursion(int natural_number);

void InsertionSortingForArrayInAscendingOrder(int *unordered_array, size_t len);

int* SelectionSortingForArrayInAscendingOrder(int *unordered_data, size_t len);

int* HeapSortingForArrayInAscendingOrder(int *unordered_data, size_t len);

void Heapify(int array[], size_t N, size_t index);

void BuildHeap(int array[], size_t N);

void MergeSort(int data[], size_t p, size_t r);
void Merge(int data[], size_t p, size_t q, size_t r);

void BubbleSort(int data[], size_t N);

// P.862
unsigned long nextpow2(unsigned long X);

int ispow2(unsigned long X);

float interpolate (float    freq, 
                   double   filter_curve_db [][2],
                   int      number_of_points);
#endif  // ALGORITHM_LIBRARY_SRC_BASE_ALGORITHM_H_
