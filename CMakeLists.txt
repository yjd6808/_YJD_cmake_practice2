cmake_minimum_required(VERSION 3.14.2)

project(JD_HELLO_WORLD 
        LANGUAGES CXX 
        VERSION 1.2.3
)

message("[project setting end]")
message("\t프로젝트 명 : ${PROJECT_NAME}")
message("\t버전 : ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

add_executable(
    ${PROJECT_NAME} 
        main.cpp 
        methods.cpp
        methods2.cpp
)

message("[configuration end]")

