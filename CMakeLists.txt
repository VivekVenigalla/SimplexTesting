cmake_minimum_required(VERSION 3.20)
project(runny 
    VERSION 1.0.0 
    LANGUAGES CXX
)

# 1. Enforce Modern C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_EXTENSIONS OFF)

# 2. Define Source Files (Explicitly list them for reliable builds)
set(PROJECT_SOURCES
    src/main.cpp
    src/simplex.cpp
    src/pointCloud.cpp
    src/point.cpp
)

# 3. Define the Executable Target
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# 4. Include Header Directories
# PUBLIC tells CMake that anyone linking to this target also needs these headers.
# PRIVATE can be used if this target won't be linked by other libraries.
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 5. Compiler Warnings (Optional but highly recommended)
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()