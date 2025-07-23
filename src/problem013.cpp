// problem013.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 013" << std::endl;

    long long n = 1;
    long long t = 1;
    long long limit = 500;
    while(true) {
        t = n * (n + 1) / 2;
        ;
        if (divisor_count(t) > limit)
            break;
        n++;
    }

    std::cout << t << std::endl;

    return 0;
}
