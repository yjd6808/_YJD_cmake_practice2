message("enter subdirectory : ${CMAKE_CURRENT_SOURCE_DIR}")

project(libdiv LANGUAGES CXX VERSION 1.0.0)

add_library(${PROJECT_NAME} STATIC
    src/div.cpp 
    include/div.h
)

include_directories(include)

message("leave subdirectory : ${CMAKE_CURRENT_SOURCE_DIR}")
