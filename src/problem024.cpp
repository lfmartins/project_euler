// problem024.cpp
#include <iostream>
#include <vector>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 024" << std::endl;

    std::vector<ull> factorials(10, 0);
    factorials[0] = 1;
    for(ull i = 1; i < 10; ++i) {
        factorials[i] = factorials[i-1] * i;
    }

    std::vector<ull> digits = ull_range(0, 10); 
    ull n = 1000000;
    std::vector<ull> perm;
    ull k = 9;
    
    while(n > 0) {
        n /= factorials[k];
        if (n == 0) {
            for (ull d: digits) {
                perm.push_back(d);
            }
            return perm;
        }
        perm.push_back(digits[q]);
        digits.erase(digits.begin() + q);
        n %= factorials[k--];
    }

    for (ull v: perm) {
        std::cout << v;
    }
    std::cout << std::endl;

    return 0;
}
