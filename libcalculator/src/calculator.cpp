#include "calculator.h"

#include "div.h"
#include "mul.h"
#include "printer.h"

double calculator::div(double a, double b) {
    print_value(a);
    print_value(b);

    return __div(a, b);
}

double calculator::mul(double a, double b) {
    print_value(a);
    print_value(b);

    return __mul(a, b);
}