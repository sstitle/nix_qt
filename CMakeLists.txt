cmake_minimum_required(VERSION 3.10)

# Set the project name
project(zero-to-nix-cpp)

# Enable C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the spdlog package
find_package(spdlog REQUIRED)

# Add the executable
add_executable(zero-to-nix-cpp main.cpp)

# Link spdlog to the executable
target_link_libraries(zero-to-nix-cpp PRIVATE spdlog::spdlog)
