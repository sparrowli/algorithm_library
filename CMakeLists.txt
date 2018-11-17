# CMake requirement for minimum version
cmake_minimum_required (VERSION 2.8)

# project information
project (algorithm_spec)

message(STATUS "CMAKE_SYSTEM_VERSION: [${CMAKE_SYSTEM_VERSION}]")
message(STATUS "CMAKE_VERSION: [${CMAKE_VERSION}]")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/googletest)

message(STATUS "PROJECT_SOURCE_DIR : [${PROJECT_SOURCE_DIR}]")
set (PROJECT_SOURCE_FILES 
  ${PROJECT_SOURCE_DIR}/src/output_rate_calculator.cc
  ${PROJECT_SOURCE_DIR}/main.cc)

include_directories (
	${PROJECT_SOURCE_DIR}
)

add_executable (algorithm_spec ${PROJECT_SOURCE_FILES})
# target_link_libraries(test_spec PUBLIC ${GTEST_LIB})
