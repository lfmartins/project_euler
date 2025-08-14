// problem048.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 048" << std::endl;

//    ull n = 3, e = 12, m = 5;
//    ull r = power_mod(n, e, m);
//
//    std::cout << r << std::endl;
    ull nmax = 10;
    ull sum = 0;
    ull m = ull_power(10, 10);
    for(ull n = 1; n <= nmax; ++n) {
        sum = (sum + power_mod(n, n, m)) % m;
//        ull p = power_mod(n, n, m);
//        sum += p;
//        sum %= m;
//        std::cout << "n=" << n
//                  << " n^n % 10^10=" << p 
//                  << " sum= " << sum
//                  << std::endl;
    }

    std::cout << "Solution: " << sum << std::endl;
    

    return 0;
}
