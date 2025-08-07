// problem032.cpp
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <set>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 032" << std::endl;

    std::array<std::array<ull, 2>, 4> breaks{{
        {1, 5},
        {2, 5},
        {3, 5},
        {4, 5},
    }};

    std::vector<ull> perm(9, 0);
    for (ull i = 0; i < 9; ++i) {
        perm[i] = i + 1;
    }

//    ull cmax = 20;
//    ull c = 0;
    std::set<ull> prods;
    do {
//        for (size_t i = 0; i < perm.size(); ++i) {
//            std::cout << perm[i];
//        }
//        std::cout << std::endl;
        for (size_t i = 0; i < 4; ++i) {
            ull b1 = breaks[i][0], b2 = breaks[i][1];
            std::vector<ull> slice1(perm.begin(), perm.begin() + b1);
            std::vector<ull> slice2(perm.begin() + b1, perm.begin() + b2);
            std::vector<ull> slice3(perm.begin() + b2, perm.end());
            ull n1 = number_from_digits(slice1);
            ull n2 = number_from_digits(slice2);
            ull n3 = number_from_digits(slice3);
            if (n1 * n2 == n3) {
                prods.insert(n3);
            }
//            std::cout << n1 << " " << n2 << " " << n3 << std::endl;
        }
//        if (++c > cmax) {
//            break;
//        }
    } while(std::next_permutation(perm.begin(), perm.end()));

    ull sum = 0;
    for (ull n: prods) {
        sum += n;
    }

    std::cout << "Solution: " << sum << std::endl;

    return 0;
}
