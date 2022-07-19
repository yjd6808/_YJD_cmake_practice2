add_library(libsub STATIC 
	include/subtraction.h	
	src/subtraction.cpp)
# 헤더 파일은 해당 프로젝트에 포함시켜주기 위함 
# 실제로 바이너리에 포함되지 않음

target_include_directories(libsub 
	PUBLIC include
)