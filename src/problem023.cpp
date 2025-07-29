// problem023.cpp
#include <iostream>
#include <set>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 023" << std::endl;

    ull nmax = 28123;
    std::set<ull> abints;

    for (ull n = 1; n <= nmax; ++n) {
        if (is_abundant(n)) {
            abints.insert(n);
        }
    }

    ull sum = 0;
    for (ull n = 1; n <= nmax; ++n) {
        bool is_sum = false;
        for (ull a: abints) {
            if (a >= n) {
                 break;
            }
            ull b = n - a;
            if (abints.find(b) != abints.end()) {
                is_sum = true;
                break;
            }
        }
        if (!is_sum) {
            sum += n;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
