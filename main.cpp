#include <iostream>

extern const char* msg();
extern const char* name();

int main() { 
    std::cout << msg() << "\n";
    std::cout << "my name is " << name() << "\n";
    return 0;
}