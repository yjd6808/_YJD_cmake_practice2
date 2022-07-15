#include <iostream>

#include "calculator.h"
#include "printer.h"

extern const char* msg();
extern const char* name();

int main() { 
    std::cout << msg() << "\n";
    std::cout << "my name is " << name() << "\n";

    print_value(calculator::div(100, 5));
    print_value(calculator::mul(100, 5));
    print_str("작업완료");
    return 0;
}