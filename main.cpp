#include <iostream>

extern const char* msg();
extern const char* name();
extern int number();

int main() { 
    std::cout << msg() << "\n";
    std::cout << "my name is " << name() << "\n";
    std::cout << number() << "\n";
    return 0;
}