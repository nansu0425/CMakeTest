cmake_minimum_required(VERSION 3.10)

# Log the VCPKG_DIR
message(STATUS "VCPKG_DIR is set to: $ENV{VCPKG_DIR}")

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

# Add the interface library
add_library(ILib INTERFACE)

# Set the C++ standard to C++17
target_compile_features(ILib INTERFACE cxx_std_17)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	# Add the include directory for the vcpkg installed packages
	target_include_directories(ILib INTERFACE ${VCPKG_INSTALLED_DIR}/x64-windows/include)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	# Add the include directory for the vcpkg installed packages
	target_include_directories(ILib INTERFACE ${VCPKG_INSTALLED_DIR}/x64-linux/include)
else()
	message(STATUS "Unknown OS: ${CMAKE_SYSTEM_NAME}")
endif()

# add subdirectories
add_subdirectory(src)
add_subdirectory(apps)