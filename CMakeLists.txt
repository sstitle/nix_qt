cmake_minimum_required(VERSION 3.31)

# Set the project name
project(zero-to-nix-cpp)

# Enable C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the spdlog package
find_package(spdlog REQUIRED)

# Find the Boost program_options package
find_package(Boost REQUIRED COMPONENTS program_options)

# Find the Qt6 package
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Find the OpenCASCADE package
find_package(OpenCASCADE REQUIRED)

# Add the executable
add_executable(zero-to-nix-cpp main.cpp)

# Include directories for OpenCASCADE
target_include_directories(zero-to-nix-cpp PRIVATE ${OpenCASCADE_INCLUDE_DIR})

# Link spdlog, Boost program_options, Qt6 Widgets, and OpenCASCADE libraries to the executable
target_link_libraries(zero-to-nix-cpp PRIVATE spdlog::spdlog Boost::program_options Qt6::Widgets ${OpenCASCADE_LIBRARIES})
