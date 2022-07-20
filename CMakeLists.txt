cmake_minimum_required(VERSION 3.7.0)
project(calculator LANGUAGES CXX VERSION 1.0.0)

option(BUILD_SHARED_LIBS "default library type to SHARED" ON)

# 출력 경로를 동일하게 맞춰춘다.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) # 실행 프로그램 출력경로
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)	# 동적 라이브러리 출력경로
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # 정적 라이브러리 출력경로

# 하위 라이브러리 타겟들을 생성하기 위해
add_subdirectory(libadd)
add_subdirectory(libsub)
add_subdirectory(libmath)

add_executable(main_proj main.cpp)

target_link_libraries(main_proj PRIVATE libmath)


