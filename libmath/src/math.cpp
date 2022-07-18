#include "math/math.h"		// C헤더인 math.h와 겹치기 때문에 
							// math 경로를 하나더 생성해줌
							
#include "addition.h"
#include "subtraction.h"

int Math::Add(int a, int b) {
	return __add(a, b);
}

int Math::Sub(int a, int b) {
	return __subtract(a, b);
}