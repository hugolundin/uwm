cmake_minimum_required(VERSION 3.19)

project(graphics)
set (CMAKE_CXX_STANDARD 20)

include_directories(vendor/minifb/include)
add_subdirectory(vendor/minifb)

add_subdirectory(src)
