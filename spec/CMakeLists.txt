# CMake requirement for minimum version
cmake_minimum_required (VERSION 2.8)

# project information
project (algorithm_spec)

message(STATUS "CMAKE_SYSTEM_VERSION: [${CMAKE_SYSTEM_VERSION}]")
message(STATUS "CMAKE_VERSION: [${CMAKE_VERSION}]")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)

message(STATUS "PROJECT_SOURCE_DIR : [${PROJECT_SOURCE_DIR}]")
set (PROJECT_SOURCE_FILES 
  ${PROJECT_SOURCE_DIR}/src/output_rate_calculator.cc
  ${PROJECT_SOURCE_DIR}/src/base_algorithm.cc
  ${PROJECT_SOURCE_DIR}/src/lc_two_sum.cc
  ${PROJECT_SOURCE_DIR}/src/lc_add_two_numbers.cc
  ${PROJECT_SOURCE_DIR}/src/lc_longest_palindromic.cc
  ${PROJECT_SOURCE_DIR}/src/lc_longest_substring_without_repeating_characters.cc
  ${PROJECT_SOURCE_DIR}/src/lc_median_of_two_sorted_arrays.cc
  ${PROJECT_SOURCE_DIR}/src/lc_regular_expression_matching.cc
  ${PROJECT_SOURCE_DIR}/src/checks.cc
  ${PROJECT_SOURCE_DIR}/src/int_stack.cc
  ${PROJECT_SOURCE_DIR}/src/dfs.cc
  ${PROJECT_SOURCE_DIR}/spec/dfs_spec.cc
  ${PROJECT_SOURCE_DIR}/spec/linked_list_spec.cc
  ${PROJECT_SOURCE_DIR}/spec/int_queue_spec.cc
  ${PROJECT_SOURCE_DIR}/spec/int_stack_spec.cc
  ${PROJECT_SOURCE_DIR}/spec/output_rate_calculator_spec.cc
  ${PROJECT_SOURCE_DIR}/spec/base_algorithm_spec.cc
  ${PROJECT_SOURCE_DIR}/spec/safe_compare_spec.cc
  ${PROJECT_SOURCE_DIR}/spec/lc_two_sum_spec.cc
  ${PROJECT_SOURCE_DIR}/spec/lc_add_two_numbers_spec.cc
  ${PROJECT_SOURCE_DIR}/spec/lc_longest_substring_without_repeating_characters_spec.cc
  ${PROJECT_SOURCE_DIR}/spec/lc_median_of_two_sorted_arrays_spec.cc
  ${PROJECT_SOURCE_DIR}/spec/lc_longest_palindromic_spec.cc
  ${PROJECT_SOURCE_DIR}/spec/lc_regular_expression_matching_spec.cc
  ${PROJECT_SOURCE_DIR}/spec/gmock_main.cc)

include_directories (
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/googletest/googletest/include"
	"${PROJECT_SOURCE_DIR}/googletest/googlemock/include"
)

link_directories (
  "${PROJECT_SOURCE_DIR}/release/lib"
)

add_executable (algorithm_spec ${PROJECT_SOURCE_FILES})
target_link_libraries(algorithm_spec PUBLIC gmock gtest)
