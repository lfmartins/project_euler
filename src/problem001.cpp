// problem001.cpp

#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 001" << std::endl;
    
    ull sum = 0;

    for (ull i = 0; i < 1000; ++i) {
        if (i % 3 == 0 || i % 5 == 0)
           sum += i;
    }

    std::cout << sum << std::endl;

    return 0; 
}
