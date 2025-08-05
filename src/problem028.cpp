// problem028.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 028" << std::endl;

    ull nmax = 1001;
    ull sum = 1;
    for (ull n = 3; n <= nmax; n += 2) {
        ull sum_corners = 2 * (n * (2 * n - 3) + 3);
        sum += sum_corners;
    }
    std::cout << sum << std::endl;

    return 0;
}
