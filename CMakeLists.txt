cmake_minimum_required(VERSION 3.15)

project(graphviz VERSION 0.0.1 LANGUAGES CXX)

# Set prefix path for qt install folder
set($(CMAKE_PREFIX_PATH))

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

# Add the main executable target
# subjecto of change
add_executable(my_project_executable)

# Add source files to the target
target_sources(my_project_executable PRIVATE
    src/main.cpp
)

# Include directories for the target
target_include_directories(my_project_executable PRIVATE
    include
)

add_subdirectory(libs)
add_subdirectory(tests)
add_subdirectory(qt_part)
