cmake_minimum_required(VERSION 3.14)

project(math_mosee VERSION 1.0.0 LANGUAGES CXX)

add_library(math_mosee INTERFACE)

target_include_directories(math_mosee INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(math_mosee INTERFACE cxx_std_17)