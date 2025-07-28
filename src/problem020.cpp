// problem019.cpp
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <tools.h>

using boost::multiprecision::cpp_int;

int main() {
    std::cout << "Solving Project Euler Problem 019" << std::endl;

    ull n = 100;
    cpp_int factorial = 1;

    for (ull i = 2; i <= n; ++i) {
        factorial *= i;
    }

    cpp_int digit_sum = 0;
    while (factorial > 0) {
        digit_sum += factorial % 10;
        factorial /= 10;
    }

    std::cout << digit_sum << std::endl;

    return 0;
}
