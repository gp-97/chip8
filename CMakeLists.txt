cmake_minimum_required(VERSION 3.18)

project(chip8)
set(${PROJECT_NAME} chip8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(include)
