// problem031.cpp
#include <algorithm>
#include <iostream>
#include <iterator>
#include <tools.h>


int main() {
    std::cout << "Solving Project Euler Problem 031" << std::endl;

    ull denominations[] = {1, 2, 5, 10, 20, 50, 100, 200};
    constexpr ull ndenoms = 8;
    constexpr ull target = 200;
    ull solution_counts[ndenoms][target + 1] = {0};

    for (size_t j = 0; j <= target; ++j)
        if (j % denominations[0] == 0)
            solution_counts[0][j] = 1;

    for(size_t i = 1; i < ndenoms; ++i)
        for (size_t j = 0; j <= target; ++j)
            for (int k = j; k >= 0; k -= denominations[i])
                solution_counts[i][j] += solution_counts[i - 1][k];
     
    std::cout << solution_counts[ndenoms - 1][target] << std::endl;

    return 0;
}
