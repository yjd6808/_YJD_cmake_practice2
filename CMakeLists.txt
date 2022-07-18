cmake_minimum_required(VERSION 3.7.1)
project(main_proj LANGUAGES CXX VERSION 1.0.0)	# 솔루션

# 출력 경로 설정
set(${CMAKE_RUNTIME_OUTPUT_DIRECTORY} "${CMAKE_BINARY_DIR}/bin") # 실행파일 출력경로
set(${CMAKE_ARCHIVE_OUTPUT_DIRECTORY} "${CMAKE_BINARY_DIR}/lib") # 정적 lib 출력경로

# 하위 라이브러리 연결
add_subdirectory(libmath)
add_subdirectory(libadd)
add_subdirectory(libsub)

add_executable(main_proj main.cpp)				# 프로젝트

target_link_libraries(main_proj PRIVATE libmath)