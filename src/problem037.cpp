// problem037.cpp
#include <iostream>
#include <tools.h>

bool is_truncatable(ull n) {
    if (n < 10)
        return false;

    ull nn = n;
    ull ndigits = 0;
    while (nn > 0) {
        if (!is_prime(nn))
            return false;
        nn /= 10;
        ++ndigits;
    }
            
    ull pten = 10;
    for (ull i=0; i < ndigits; i++) {
        ull m = n % pten;
        if (!is_prime(m))
            return false;
        pten *= 10;
    }

    return true;
}

int main() {
    std::cout << "Solving Project Euler Problem 037" << std::endl;

    ull count = 0;
    ull limit = 11;
    ull sum = 0;
    for (ull n = 10; true; ++n) 
        if (is_truncatable(n)) {
            std::cout << n << std::endl;
            sum += n;
            ++count;
            if (count >= limit)
                break;
        }

    std::cout << "Solution: " << sum << std::endl;

    return 0;
}
