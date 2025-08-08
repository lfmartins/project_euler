// problem033.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 033" << std::endl;

    ull num_answer = 1, den_answer = 1;
    for (ull d1 = 1; d1 <= 9; ++d1) {
        for (ull d2 = 1; d2 <= 9; ++d2) {
            for (ull d3 = 1; d3 <= 9; ++d3) {
                ull num = 10 * d1 + d2;
                ull den = 10 * d2 + d3;
                if (num == den) {
                    continue;
                }
                if (num * d3 == den * d1) {
                    std::cout << num << "/" << den << " = " << d1 << "/" << d3 << std::endl;
                    num_answer *= d1;
                    den_answer *= d3;
                }
            }
        }
    }

    ull g = gcd(num_answer, den_answer);
    std::cout << "Solution: " << den_answer / g << std::endl;

    return 0;
}
