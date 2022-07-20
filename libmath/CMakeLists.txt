add_library(libmath SHARED 
	include/math/math.h
	src/math.cpp
)

# 계산기 프로그램에서도 포함되어야하는 디렉토리이므로 PUBLIC으로 설정
# 따라서 libmath의 추가 포함디렉토리 목록은 아래와 같다.
#
# libmath/include
# libadd/include
# libsub/include
target_include_directories(libmath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# libadd와 libsub는 math라이브러리에서만 링크되므로 PRIVATE으로 둠
target_link_libraries(libmath PRIVATE libadd libsub)

