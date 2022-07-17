
message("enter subdirectory : ${CMAKE_CURRENT_SOURCE_DIR}")

project(libcommon LANGUAGES CXX VERSION 1.0.0)

add_library(${PROJECT_NAME} 
    src/printer.cpp 
    include/printer.h
)

include_directories(include)
get_target_property(proj_type ${PROJECT_NAME} TYPE)

if (${proj_type} STREQUAL "STATIC_LIBRARY")

elseif(${proj_type} STREQUAL "SHARED_LIBRARY")
    target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR}/exports)
    generate_export_header(${PROJECT_NAME} EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/${PROJECT_NAME}_export.h)
endif()

message("leave subdirectory : ${CMAKE_CURRENT_SOURCE_DIR}")
