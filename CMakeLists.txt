cmake_minimum_required(VERSION 3.14.2)


message("\t프로젝트 명 : ${PROJECT_NAME}")
message("\t컴파일러 : ${CMAKE_CXX_COMPILER}")
message("\t버전 : ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

project(JD_HELLO_WORLD 
        LANGUAGES CXX 
        VERSION 1.2.4
)

# 5초간 슬립
# execute_process(COMMAND sleep 5 RESULT_VARIABLE result)

message("[project setting end]")
message("\t프로젝트 명 : ${PROJECT_NAME}")
message("\t컴파일러 : ${CMAKE_CXX_COMPILER}")
message("\t버전 : ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

add_executable(
    ${PROJECT_NAME} 
        main.cpp 
        methods.cpp
        methods2.cpp
)

message("[configuration end]")

