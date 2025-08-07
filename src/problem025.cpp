// problem025.cpp
#include <iostream>
#include <cmath>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 025" << std::endl;

    double phi = (1 + std::sqrt(5)) / 2;
    double c = 1 / std::sqrt(5);
    ull nmin = static_cast<ull>(std::floor((999 - std::log10(c)) / std::log10(phi)));
    ull nmax = static_cast<ull>(std::floor((1000 - std::log10(c)) / std::log10(phi)));
    for (ull n = nmin; n <= nmax; n++) {
        double dlog_fib_approx = std::log10(c) +
                          n * std::log10(phi);
        ull ndigits = 1 + static_cast<ull>(std::floor(dlog_fib_approx));
        if (ndigits == 1000) {
            std::cout << "Solution: " << n << std::endl;
            return 0;
        }
    }

    std::cout << "No solution found" << std::endl;

    return 0;
}
