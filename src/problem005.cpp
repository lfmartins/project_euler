#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 005" << std::endl;
    
    long long n = 20;
    long long l = lcm(range(1, n));
    std::cout << l << std::endl;

    return 0;
}
