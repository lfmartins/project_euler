// problem006.cpp
#include <iostream>
#include <vector>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 006" << std::endl;

    ull n = 100;
    ull solution = n * (n + 1) * (3 * n * n - n - 2) / 12;

    std::cout << "Solution: " << solution << std::endl;

    return 0;
}
