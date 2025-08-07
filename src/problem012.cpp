// problem012.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 012" << std::endl;

    ull t = 1;
    ull i = 2;
    ull target = 500;

    while(true) {
        ull ndiv = divisors_count(t);
        if (ndiv > target)
            break;
        t += i++;
    }
    
    std::cout << "Solution: " << t << std::endl;

    return 0;
}
