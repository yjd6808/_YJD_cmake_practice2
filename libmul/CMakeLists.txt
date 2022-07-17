message("enter subdirectory : ${CMAKE_CURRENT_SOURCE_DIR}")

project(libmul LANGUAGES CXX VERSION 1.0.0)

add_library(${PROJECT_NAME} STATIC
    src/mul.cpp 
    include/mul.h
)

include_directories(include)

message("leave subdirectory : ${CMAKE_CURRENT_SOURCE_DIR}")
