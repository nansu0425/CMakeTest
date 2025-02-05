cmake_minimum_required(VERSION 3.10)

# set the project name
project(CMakeTest)

# add the executable
add_executable(CMakeTest main.cpp)

# add compiler interface library
add_library(CompilerInterface INTERFACE)
target_compile_features(CompilerInterface INTERFACE cxx_std_17)

# link the executable to the compiler interface library
target_link_libraries(CMakeTest PRIVATE CompilerInterface)
