// problem014.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 014" << std::endl;
    
    ull start_limit = 1000000;

    ull max_len = 0;
    ull max_start = 0;
    for (ull start = 1; start <= start_limit; ++start) {
        ull x = start;
        ull len = 1;
        while (x != 1) {
            ++len;
            if (x % 2 == 0)
                x /= 2;
            else
                x = 3 * x + 1;
        }
        if (len > max_len) {
            max_len = len;
            max_start = start;
        }
    }
    
    std::cout << "Solution: " << max_start << std::endl;

    return 0;
}
