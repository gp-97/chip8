cmake_minimum_required(VERSION 3.18)

project(Chip8)
set(${PROJECT_NAME} Chip8)

file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(include)
