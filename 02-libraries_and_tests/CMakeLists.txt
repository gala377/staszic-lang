cmake_minimum_required(VERSION 3.10)

project(StaszicLang)

# generate compile commands file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set c++ standard to c++17
set(CMAKE_CXX_STANDARD 17)
# Set the debug build to list more information
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -Wall")
# set code optimalizations for the release 
# to the absolute maximum
set(CMAKE_CXX_FLAGS_RELEASE "{CMAKE_CXX_FLAGS} -o4") 
 # set the compiler we'll use
 # set it to the path of the one you use
set(CMAKE_CXX_COMPILER "clang++")

include_directories(inc)

add_subdirectory(src)
add_subdirectory(tests)

enable_testing()
add_test(NAME All COMMAND Test)
