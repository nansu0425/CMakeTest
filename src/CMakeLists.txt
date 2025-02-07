# Add the library
add_library(Lib STATIC Functions.cpp)

# Link the interface library
target_link_libraries(Lib PUBLIC ILib)

# Include the current directory
target_include_directories(Lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
