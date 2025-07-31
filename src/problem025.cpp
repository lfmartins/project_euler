// problem025.cpp
#include <iostream>
#include <cmath>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 025" << std::endl;

    double phi = (1 + std::sqrt(5)) * 0.5;
    double psi = (1 - std::sqrt(5)) * 0.5;
    double c = 1 / sqrt(5);

    ull ndigits = 1000;

    ull n = static_cast<ull>(std::floor((ndigits - std::log10(c)) / std::log10(phi)));

    std::cout << n << std::endl;
    
    return 0;
}
