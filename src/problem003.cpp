// problem003.cpp
#include <iostream>
#include <vector>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 003" << std::endl;
    
    ull v = 600851475143ULL;
    std::vector<fterm> factors = factor(v);
    std::cout << factors.back().p << std::endl;
    
    return 0;
}
