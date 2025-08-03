// problem027.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 027" << std::endl;


    ll limit = 10;
    for(ll a = -limit; a <= limit; ++a) {
        for(ll b = -limit; b <= limit; ++b) {
            std::cout << "a=" << a << " b=" << b << std::endl;
            for (ull n =0; n <= 100; ++n) {
                ll f = n * n + a * n + b;
                bool p = is_prime(f);
                std::cout << "   n=" << n << " f(n)=" << fn << " prime=" << p << std::endl;
                if (p)
                    break;
            }
        }
    }

    return 0;
}
