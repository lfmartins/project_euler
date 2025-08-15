// problem029.cpp
#include <iostream>
#include <tools.h>

ull prime_exp(ull n, ull p) {
    ull e = 0;
    while (n % p == 0) {
        n /= p;
        ++e;
    }
    return e;
}

bool check(ull a, ull b, ull c, ull d) {
    for (ull p: primes_base) {
        if (p > a || p > c) {
            return true;
        }
        ull k = prime_exp(a, p);
        ull l = prime_exp(c, p);
        if (k * b != l * d) {
            return false;
        }
    }
    return true;
}


int main() {
    std::cout << "Solving Project Euler Problem 029" << std::endl;

    ull limit = 100;
    ull count = 0;
    for (ull a = 2; a <= limit; ++a) {
        for (ull b = 2; b <= limit; ++b) {
//            std::cout << a << " " << b;
            bool counted = false;
            for (ull c = 2; c < a; ++c) {
                if (counted) {
                    break;
                }
                for (ull d = 2; d <= limit; d++) {
                    if (check(a, b, c, d)) {
                        counted = true;
//                        std::cout << " counted " << c << " " << d;
                        break;
                    }
                }
            }
            if (!counted) {
                ++count;
            }
//            std::cout << std::endl;
        }
    }

    std::cout << "Solution: " << count << std::endl;

    return 0;
}
