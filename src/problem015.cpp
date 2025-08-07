// problem015.cpp
#include <iostream>
#include <array>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 015" << std::endl;

    const ull sz = 20;
    std::array<std::array<ull, sz + 1>, sz + 1> table{};

    for(ull i = 0; i <= sz; ++i) {
        table[i][0] = table[0][i] = 1;
    }

    for(ull i = 1; i <= sz; ++i)
        for(ull j = 1; j <= sz; ++j) {
            table[i][j] = table[j][i] = table[i-1][j] + table[i][j-1];
        }

    std::cout << "Solution: " << table[sz][sz] << std::endl;

    return 0;
}
