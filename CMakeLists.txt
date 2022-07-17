include(function.cmake)
include(GenerateExportHeader)

cmake_minimum_required(VERSION 3.14.2)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

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
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY      ${CMAKE_BINARY_DIR}/bin/)
set(CMAKE_PDB_OUTPUT_DIRECTORY          ${CMAKE_BINARY_DIR}/bin/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY      ${CMAKE_BINARY_DIR}/bin/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY      ${CMAKE_BINARY_DIR}/bin/)

add_subdirectory(libcalculator)
add_executable(
    ${PROJECT_NAME} 
        main.cpp 
        methods.cpp
        methods2.cpp
)




#set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
#set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
#set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
#set_target_properties(${PROJECT_NAME} PROPERTIES PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

target_link_libraries(${PROJECT_NAME} PRIVATE libcalculator)



message("[configuration end]")

