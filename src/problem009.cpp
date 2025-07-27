// problem009.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 009" << std::endl;
    
    ull n = 1000;
    for (triple<ull> pt: pythagorean_triples(1000)) {
        ull s = pt.a + pt.b + pt.c;
        if (n % s != 0)
            continue;
        ull k = n / s;
        ull a = k * pt.a;
        ull b = k * pt.b;
        ull c = k * pt.c;
        ull p = a * b * c;
        std::cout << p << std::endl;
    }

    return 0;
}
