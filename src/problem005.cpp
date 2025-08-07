// problem005.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 005" << std::endl;
    
    ull n = 20;
    ull solution = lcm(ull_range(1, n));

    std::cout << "Solution: "<< solution << std::endl;

    return 0;
}
