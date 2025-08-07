// problem002.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 002" << std::endl;

    ull f1 = 1, f2 = 2;
    ull sum = 0;

    while (f2 <= 4000000ULL) {
        if (f2 % 2 == 0) {
            sum += f2;
        }
        ull f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    
    std::cout << "Solution: " << sum << std::endl;

    return 0;
}
