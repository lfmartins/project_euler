// problem005.cpp

#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 005" << std::endl;
    
    ull n = 20;
    ull l = lcm(ull_range(1, n));
    std::cout << l << std::endl;

    return 0;
}
