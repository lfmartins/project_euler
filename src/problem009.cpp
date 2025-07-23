// problem009.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 009" << std::endl;
    
    long long n = 1000;
    for (triple<long long> pt: pythagorean_triples(1000)) {
        long long s = pt.a + pt.b + pt.c;
        if (n % s != 0)
            continue;
        long long k = n / s;
        long long a = k * pt.a;
        long long b = k * pt.b;
        long long c = k * pt.c;
        long long p = a * b * c;
        std::cout << p << std::endl;
    }

    return 0;
}
