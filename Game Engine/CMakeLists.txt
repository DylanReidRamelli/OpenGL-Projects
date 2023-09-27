cmake_minimum_required(VERSION 3.5...3.19)
cmake_policy(SET CMP0048 NEW)
project(GameEngine VERSION 0.0.1
  LANGUAGES "CXX" "C")

include(CMakePackageConfigHelpers)
include(cmake/Functions.cmake)

add_library(GameEngine INTERFACE)
target_include_directories(GameEngine INTERFACE src/)

add_executable(main drivers/main.cpp)
target_link_libraries(main GameEngine)

target_compile_features(GameEngine INTERFACE cxx_std_17)