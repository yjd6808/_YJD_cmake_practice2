cmake_minimum_required(VERSION 3.21)

message("enter subdirectory : ${CMAKE_CURRENT_SOURCE_DIR}")


project(libcalculator
    LANGUAGES CXX
    VERSION 1.0.0)

add_library(${PROJECT_NAME} STATIC 
    src/calculator.cpp 
    include/calculator.h)

set(libcommon_dir   ../libcommon)
set(libdiv_dir      ../libdiv)
set(libmul_dir      ../libmul)

add_subdirectory(${libcommon_dir} ${libcommon_dir}/build EXCLUDE_FROM_ALL)
add_subdirectory(${libdiv_dir} ${libdiv_dir}/build       EXCLUDE_FROM_ALL)
add_subdirectory(${libmul_dir} ${libmul_dir}/build       EXCLUDE_FROM_ALL)

target_include_directories(${PROJECT_NAME} 
    PUBLIC  include
    PUBLIC  ${libcommon_dir}/include
    PRIVATE ${libmul_dir}/include
    PRIVATE ${libdiv_dir}/include
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE  libmul 
    PRIVATE  libdiv
    PUBLIC   libcommon)

set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

message("leave subdirectory : ${CMAKE_CURRENT_SOURCE_DIR}")
