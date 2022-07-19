add_library(libcalculator STATIC
	include/calculator.h
	src/calculator.cpp)
# 헤더 파일은 해당 프로젝트에 포함시켜주기 위함 
# 실제로 바이너리에 포함되지 않음

target_include_directories(libcalculator 
	PUBLIC include
)

target_link_libraries(libcalculator
	PRIVATE   libadd
	PRIVATE   libsub
)

target_link_directories(libcalculator
	INTERFACE ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
)

