// problem034.cpp
#include <iostream>
#include <vector>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 034" << std::endl;

    std::vector<ull> factorials(10, 0);
    factorials[0] = 1;
    for (ull d = 1; d < 10; ++d) {
        factorials[d] = d * factorials[d-1];
    }

    ull result = 0;
    for (ull k = 2; ull_power(10, k - 1) < factorials[9] * k; ++k) {
        std::cout << k << "-digit numbers" << std::endl;
        for (ull m = ull_power(10, k - 1); m < ull_power(10, k); ++m) {
            std::vector<ull> digits = digits_from_number(m);
            ull sum = 0;
            for(ull d: digits) {
                sum += factorials[d];
            }
            if (m == sum) {
                std::cout << m << std::endl;
                result += m;
            }
        }
    }

    std::cout << "Solution: " << result << std::endl;

    return 0;
}
