// problem030.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 030" << std::endl;

    ull n = 5;
    std::vector<ull> powers(10, 0);
    for (ull d = 0; d < 10; ++d) {
        powers[d] = ull_power(d, n);
    }

    std::vector<ull> solutions;
    for (ull k = 2; ull_power(10, k - 1) < powers[9] * k; ++k) {
        std::cout << k << "-digit numbers" << std::endl;
        for (ull m = ull_power(10, k - 1); m < ull_power(10, k); ++m) {
            std::vector<ull> digits = digits_from_number(m);
            ull sum = 0;
            for (ull d: digits) {
                sum += powers[d];
            }
            if (m == sum) {
                std::cout << m << std::endl;
                solutions.push_back(m);
            }
        }
    }

    ull result = 0;
    for (ull s: solutions) {
        result += s;
    }
    std::cout << result << std::endl;

    return 0;
}
