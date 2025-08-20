cmake_minimum_required(VERSION 3.10)

# Project info
project(StackQueueLib LANGUAGES CXX)

# Require C++17 (or newer if you want)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add include directory for headers
include_directories(include)

# Main demo executable
add_executable(stack_queue_demo
    src/main.cpp
)

# If you want to add test executables later:
# add_executable(test_stack tests/test_stack.cpp)
# add_executable(test_queue tests/test_queue.cpp)
# target_link_libraries(test_stack PRIVATE stack_queue_lib)
# target_link_libraries(test_queue PRIVATE stack_queue_lib)

