add_library(libsub STATIC 
	include/suber/subtraction.h
	src/subtraction.cpp
)

# 수학 라이브러리에서도 포함되어야하는 디렉토리이므로 PUBLIC으로 설정
target_include_directories(libsub PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)




