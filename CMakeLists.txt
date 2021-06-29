cmake_minimum_required(VERSION 3.10)

project(dspc++ CXX)

add_executable(${PROJECT_NAME} src/main.cpp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

set(SRC_FILES
    src/main.cpp
)
