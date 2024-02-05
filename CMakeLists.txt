
cmake_minimum_required(VERSION 3.14) # Minimum version of CMake
project(MyChessProject VERSION 1.0)  # Project name and version

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the src directory
add_subdirectory(src)

# Include the tests directory
enable_testing() # Enables testing with CTest
add_subdirectory(tests)
