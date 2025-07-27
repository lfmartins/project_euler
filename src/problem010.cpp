// problem010.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 010" << std::endl;

    std::cout << ull_sum(sieve(2000000)) << std::endl;

    return 0;
}
