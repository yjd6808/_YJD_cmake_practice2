#include "calculator.h"		// C헤더인 math.h와 겹치기 때문에 
							// math 경로를 하나더 생성해줌
							
#include "addition.h"
#include "subtraction.h"

int Calculator::Add(int a, int b) {
	return __add(a, b);
}

int Calculator::Sub(int a, int b) {
	return __subtract(a, b);
}