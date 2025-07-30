// problem024.cpp
#include <iostream>
#include <vector>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 024" << std::endl;

    std::vector<ull> digits = ull_range(0, 10); 
    ull n = 1000000 - 1; // List of permuations is 0-based.
    std::vector<ull> perm;
    
    for (ull k = digits.size(); k > 0; --k) {
        ull fact = factorial(k - 1);
        ull q = n / fact;
        perm.push_back(digits[q]);
        digits.erase(digits.begin() + q);
        n %= fact;
        if (n == 0)
            break;
    }
    for (ull d: digits) {
        perm.push_back(d);
    }

    for (ull v: perm) {
        std::cout << v;
    }
    std::cout << std::endl;

    return 0;
}
