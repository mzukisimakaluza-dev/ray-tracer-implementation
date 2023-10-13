cmake_minimum_required(VERSION 3.10)

project(ray_tracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/tracer)
add_subdirectory(unit_tests)
