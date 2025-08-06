// problem001.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 001" << std::endl;

    ull nmax = 1000;
    ull sum = 0;
    for (ull n = 1; n < nmax; ++n) {
        if (n % 3 == 0 || n % 5 == 0) {
            sum += n;
        }
    }
    
    std::cout << sum << std::endl;

    return 0;
}
