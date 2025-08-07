// problem046.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 048" << std::endl;

    for (ull n = 3;; n += 2) {
        if (is_prime(n)) {
            continue;
        }

        bool found_it = false;
        for (ull p: primes_base) {
            if (p == 2) {
                continue;
            }
            if (p > n) {
                found_it = true;
                break;
            }
            if (is_square((n - p) / 2)) {
                break;
            }
        }
        if (found_it) {
            std::cout << "Solution: " << n << std::endl;
            break;
        }
    }

    return 0;
}
