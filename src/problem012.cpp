// problem012.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 012" << std::endl;

    long long t = 1;
    long long i = 2;
    long long target = 500;

    while(true) {
        long long ndiv = divisor_count(t);
        if (ndiv > target)
            break;
        t += i++;
    }
    std::cout << t << std::endl;

    return 0;
}
