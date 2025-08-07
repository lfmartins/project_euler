// problem035.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 037" << std::endl;

    ull cp_count = 0;
    for(ull p: primes_base) {
        ull k = 0;
        for (ull p10 = 1; p10 < p; p10 *= 10) {
            ++k;
        }
    
        ull pp = p;
        bool is_cp = true;
        for (ull i = 0; i < k; ++i) {
            pp = (pp / 10) + ull_power(10, k - 1) * (pp % 10);
            if (!is_prime(pp)) {
                is_cp = false;
                break;
            }
        }
        if (is_cp) {
            ++cp_count;
        }
    }

    std::cout << "Solution: " << cp_count << std::endl;

    return 0;
}
