cmake_minimum_required(VERSION 3.21)

message("enter subdirectory : ${CMAKE_CURRENT_SOURCE_DIR}")

set(libcommon_dir   ../libcommon)
set(libdiv_dir      ../libdiv)
set(libmul_dir      ../libmul)


project(libcalculator
    LANGUAGES CXX
    VERSION 1.0.0)

add_library(${PROJECT_NAME} 
    src/calculator.cpp 
    include/calculator.h)

add_subdirectory(${libcommon_dir} ${libcommon_dir}/build EXCLUDE_FROM_ALL)
add_subdirectory(${libdiv_dir}    ${libdiv_dir}/build    EXCLUDE_FROM_ALL)
add_subdirectory(${libmul_dir}    ${libmul_dir}/build    EXCLUDE_FROM_ALL)

target_include_directories(${PROJECT_NAME} 
    PUBLIC  include
    PUBLIC  ${libcommon_dir}/include
    PRIVATE ${libmul_dir}/include
    PRIVATE ${libdiv_dir}/include
)



print_target_libraries(${PROJECT_NAME} "${PROJECT_NAME}의 라이브러리 링크/인클루드 정보")

get_target_property(proj_type ${PROJECT_NAME} TYPE)

if (${proj_type} STREQUAL "STATIC_LIBRARY")
    target_link_libraries(${PROJECT_NAME} 
        INTERFACE  libmul 
        INTERFACE  libdiv
        INTERFACE  libcommon
    )
elseif(${proj_type} STREQUAL "SHARED_LIBRARY")
    target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR}/exports)
    generate_export_header(${PROJECT_NAME} EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/${PROJECT_NAME}_export.h)

    target_link_libraries(${PROJECT_NAME} 
        PRIVATE    libmul 
        PRIVATE    libdiv
        PUBLIC     libcommon
    )
endif()

message("leave subdirectory : ${CMAKE_CURRENT_SOURCE_DIR}")
