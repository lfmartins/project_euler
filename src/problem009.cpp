// problem009.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 009" << std::endl;
    
    ull n = 1000;
    ull solution = 0;
    for (triple<ull> pt: pythagorean_triples(n)) {
        ull s = pt.a + pt.b + pt.c;
        if (n % s == 0) {
            ull k = n / s;
            ull a = k * pt.a, b = k * pt.b, c = k * pt.c;
            solution = a * b * c;
            break;
        }
    }

    std::cout << "Solution: " << solution << std::endl;

    return 0;
}
