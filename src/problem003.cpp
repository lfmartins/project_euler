#include <iostream>
#include <vector>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 003" << std::endl;
    
    long long v = 600851475143LL;
    std::vector<fterm> factors = factor(v);
    std::cout << factors.back().p << std::endl;
    
    return 0;
}
