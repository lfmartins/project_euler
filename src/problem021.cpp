// problem021.cpp
#include <iostream>
#include <set>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 021" << std::endl;

    ull bound = 10000;
    std::vector<ull> dsums(bound + 1, 0);
    for (ull m = 1; m <= bound; ++m) {
        dsums[m] = proper_divisors_sum(m);
    }

//    for(ull i = 1; i < dsums.size(); ++i) {
//        std::cout << "i= " << i << " " << dsums[i] << std::endl;
//    }

    std::set<ull> amicables;
    for (ull m = 2; m < bound; ++m) {
        for (ull n = m + 1; n <= bound; ++n) {
            if (dsums[m] == n && dsums[n] == m) {
//                std::cout << m << " " << n << std::endl;
                amicables.insert(m);
                amicables.insert(n);
            }
        }
    }

//    for(ull n: amicables) {
//        std::cout << n << " ";
//    }

    ull amicables_sum = 0;
    for (ull n: amicables) {
        amicables_sum += n;
    }

    std::cout << amicables_sum << std::endl;

    return 0;
}
