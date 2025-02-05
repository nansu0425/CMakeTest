# Add the app
add_executable(App Main.cpp)

# Link the library
target_link_libraries(App PRIVATE Lib)
