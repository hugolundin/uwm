cmake_minimum_required(VERSION 3.19)

project(graphics)
set (CMAKE_CXX_STANDARD 20)

include_directories(vendor/minifb/include)
add_subdirectory(vendor/minifb)

include_directories(vendor/rpclib/include)
# https://stackoverflow.com/questions/14077611/how-do-i-tell-cmake-to-link-in-a-static-library-in-the-source-directory
# Note: You need to make the `build` directory and build the dependency with cmake manually.
add_library(rpc STATIC IMPORTED)
set_target_properties(rpc PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/vendor/rpclib/build/librpc.a)

include_directories(vendor/readerwriterqueue)
add_subdirectory(vendor/readerwriterqueue)

find_package(nng REQUIRED)
find_package(Threads)
find_package(nngpp REQUIRED)

add_subdirectory(src)
