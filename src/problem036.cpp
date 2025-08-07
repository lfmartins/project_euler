// problem036.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 036" << std::endl;

//    ull n = 585;
//
//    std::cout << is_palindromic(n) << std::endl;

    ull limit = 1000000;
    ull sum = 0;

    for (ull n = 1; n < limit; ++n) {
        if (is_palindromic(n) && is_palindromic(n, 2)) {
            sum += n;
        }
    }

    std::cout << "Solution: " << sum << std::endl;

    return 0;
}
