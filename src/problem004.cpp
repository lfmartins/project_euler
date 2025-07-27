// problem004.cpp

#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 004" << std::endl;

    for (int a = 9; a > 0; --a)
        for (int b = 9; b >= 0; --b)
            for (int c=9; c >= 0; --c) {
                ull aa = static_cast<ull>(a),
                    bb = static_cast<ull>(b),
                    cc = static_cast<ull>(c);
                std::vector<ull> digits {aa, bb, cc, cc, bb, aa};
                ull n = number_from_digits(digits);
                for (ull m = 100; m < 1000; ++m) {
                    ull q = n / m;
                    if (q < 100)
                        break;
                    if (q <= 1000 && m * q == n) {
                        std::cout << n << std::endl;
                        return 0;
                    }
                }
            }
    std::cout << "No solutions" << std::endl;

    return 0;
}
