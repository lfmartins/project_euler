// problem041.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 041" << std::endl;

    for (ull ndigits=9; ndigits>0; --ndigits) {
        std::cout << ndigits << "-digit numbers" << std::endl;
        std::vector<ull> perm(ndigits);
        for (size_t i = 0; i < ndigits; ++i) {
            perm[i] = ndigits - i;
        }
        do {
            ull n = number_from_digits(perm);
            if (is_prime(n)) {
                std::cout << "Solution: " << n << std::endl;
                return 0;
            }
        } while (std::prev_permutation(perm.begin(), perm.end()));
    }

    std::cout << "Error!" << std::endl;
        
    return 1;
}

