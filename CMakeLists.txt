cmake_minimum_required(VERSION 3.10)

# Project name and a few useful settings
project(
	CMakeTest
	VERSION 1.0
	LANGUAGES CXX
)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Let's nicely support folders in IDE's
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message(STATUS "VCPKG_INSTALLED_DIR is set to: ${VCPKG_INSTALLED_DIR}")

# Add the interface library
add_library(ILib INTERFACE)

# Set the C++ standard to C++17
target_compile_features(ILib INTERFACE cxx_std_17)

# Add the vcpkg include directory
target_include_directories(ILib INTERFACE ${VCPKG_INSTALLED_DIR}/x64-windows/include)

# add subdirectories
add_subdirectory(src)
add_subdirectory(apps)