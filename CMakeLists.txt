cmake_minimum_required(VERSION 3.23)
project(gol)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)
include_directories(include)
add_executable(gol src/main.cpp src/grid.cpp)

target_link_libraries(gol
  PRIVATE
    raylib
)