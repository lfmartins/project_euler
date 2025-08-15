// problem048.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 048" << std::endl;

    ull nmax = 1000;
    ull sum = 0;
    ull m = 10'000'000'000ull;
    for(ull n = 1; n <= nmax; ++n) {
        sum = (sum + power_mod(n, n, m)) % m;
    }

    std::cout << "Solution: " << sum << std::endl;

    return 0;
}
