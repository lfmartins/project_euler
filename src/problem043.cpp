// problem043.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <tools.h>

bool check(std::vector<ull> digits) {

    for (size_t i = 1; i <= 7; ++i) {
        ull v = digits[i] * 100 + digits[i + 1] * 10 + digits[i + 2];
        if (v % primes_base[i - 1] != 0) {
            return false;
        }
//        std::cout << i << " " << v << std::endl;
    }

    return true;
}

int main() {
    std::cout << "Solving Project Euler Problem 043" << std::endl;

    std::vector<ull> digits(10);
    for (size_t i = 0; i < 10; ++i) {
        digits[i] = i;
    }

    ull sum = 0;
    do {
        if (digits[0] == 0) {
            continue;
        }

        if (check(digits)) {
            sum += number_from_digits(digits);
        }
    } while (std::next_permutation(digits.begin(), digits.end()));

    std::cout << "Solution: " << sum << std::endl;

    return 0;
}


