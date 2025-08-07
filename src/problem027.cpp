// problem027.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 027" << std::endl;
    
    ll limit = 1000;
    ll nmax = 0;
    ll amax = 0, bmax = 0;
    for (ll a = -limit + 1; a <= limit -1; ++a) {
        for (ll b = 1; b <= limit; ++b) {
            ll n = 0;
            while(true) {
                ll v = n * (n + a) + b;
                if (v <= 0 || !is_prime(v)) {
                    break;
                }
                ++n;
            }
            if (n > nmax) {
                nmax = n;
                amax = a;
                bmax = b;
            }
        }
    }

    std::cout << "nmax=" << nmax << " a=" << amax << " b=" << bmax << std::endl;
    std::cout << "Solution: " << amax * bmax << std::endl;

    return 0;
}
