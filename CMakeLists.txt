cmake_minimum_required(VERSION 3.7.0)
project(static_example LANGUAGES CXX VERSION 1.0.0)

# 실행 프로그램 타겟 생성
add_executable(hello_world main.cpp)

# 라이브러리 타겟 생성
add_library(libadd STATIC
	addition.cpp
	addition.h		# 프로젝트에 추가시켜주기 위함(바이너리에 포함되지는 않음)
)

target_link_libraries(hello_world PRIVATE libadd)


