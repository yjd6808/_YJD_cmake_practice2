cmake_minimum_required(VERSION 3.14.2)


project(JD_HELLO_WORLD 
        LANGUAGES CXX 
        VERSION 1.2.4
)

message("[project setting end]")
message("\t프로젝트 명 : ${PROJECT_NAME}")
message("\t컴파일러 : ${CMAKE_CXX_COMPILER}")
message("\t버전 : ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(libtest)
add_executable(
    ${PROJECT_NAME} 
        main.cpp 
        methods.cpp
        methods2.cpp
)

message("[configuration end]")

