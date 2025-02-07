cmake_minimum_required(VERSION 3.10)

# VCPKG_DIR environment variable must be set
if(NOT DEFINED ENV{VCPKG_DIR})
    message(FATAL_ERROR "Error: VCPKG_DIR environment variable is not set. Please set it before running CMake.")
endif()

message(STATUS "VCPKG_INSTALLED_DIR is set to: ${VCPKG_INSTALLED_DIR}")
message(STATUS "VCPKG_TARGET_TRIPLET is set to: ${VCPKG_TARGET_TRIPLET}")

set(VCPKG_INCLUDE_DIR "${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/include")

message(STATUS "VCPKG_INCLUDE_DIR is set to: ${VCPKG_INCLUDE_DIR}")

find_path(ASIO_INCLUDE_DIR NAMES asio.hpp PATHS ${VCPKG_INCLUDE_DIR})

# ASIO headers must be found
if(NOT ASIO_INCLUDE_DIR)
    message(FATAL_ERROR "Error: Asio headers not found. Make sure asio is installed via vcpkg.")
endif()

message(STATUS "ASIO_INCLUDE_DIR is set to: ${ASIO_INCLUDE_DIR}")

# Project name and a few useful settings
project(
	CMakeTest
	VERSION 1.0
	LANGUAGES CXX
)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the interface library
add_library(ILib INTERFACE)

# Set the C++ standard to C++17
target_compile_features(ILib INTERFACE cxx_std_17)

# Add the include directory for the vcpkg installed packages
target_include_directories(ILib INTERFACE ${VCPKG_INCLUDE_DIR})

# add subdirectories
add_subdirectory(src)
add_subdirectory(app)
