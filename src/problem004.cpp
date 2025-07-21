#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 004" << std::endl;

    for (int a = 9; a > 0; --a)
        for (int b = 9; b >=0; --b)
            for (int c=9; c >= 0; --c) {
                long long n = number_from_digits(std::vector<int>{a, b, c, c, b, a});
                for (long long m = 100; m < 1000; ++m) {
                    long long q = n / m;
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
