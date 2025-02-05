# Add the library
add_library(Lib STATIC Functions.cpp)

# Link the interface library
target_link_libraries(Lib PUBLIC ILib)

# Add the include directory
target_include_directories(Lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
