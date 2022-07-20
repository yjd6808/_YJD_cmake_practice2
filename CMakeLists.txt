cmake_minimum_required(VERSION 3.7.0)
project(calculator LANGUAGES CXX VERSION 1.0.0)

# 하위 라이브러리 타겟들을 생성하기 위해
add_subdirectory(libadd)
add_subdirectory(libsub)
add_subdirectory(libmath)

add_executable(main_proj main.cpp)

target_link_libraries(main_proj PRIVATE libmath)


