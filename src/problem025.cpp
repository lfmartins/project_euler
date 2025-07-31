// problem025.cpp
#include <iostream>
#include <cmath>
#include <tools.h>

ull digits_fibo(ull n) {
    double phi = (1 + std::sqrt(5)) * 0.5;
    double psi = (1 - std::sqrt(5)) * 0.5;
    double c = 1 / sqrt(5);

    return 1 + static_cast<ull>(
            std::floor(
                std::log10(
                    c * (std::pow(phi, n) - std::pow(psi, n))
                    )
                )
            );
    }
//
//    return  static_cast<ull>(std::floor(
//                n * std::log(phi) +
//                std::log10(c) +
//                std::log10(1- std::pow(psi / phi, n))
//            ));
//}

int main() {
    std::cout << "Solving Project Euler Problem 025" << std::endl;

/*
    ull nmax = 40;
    std::vector<ull> fib_seq(nmax + 1);
    fib_seq[0] = 0;
    fib_seq[1] = 1;
    for(ull n = 2; n <= nmax; ++n) {
        fib_seq[n] = fib_seq[n - 1] + fib_seq[n - 2];
    }
*/
    
    double phi = (1 + std::sqrt(5)) / 2;
//    double psi = (1 - std::sqrt(5)) / 2;
    double c = 1 / std::sqrt(5);
    ull nmin = static_cast<ull>(std::floor((999 - std::log10(c)) / std::log10(phi)));
    ull nmax = static_cast<ull>(std::floor((1000 - std::log10(c)) / std::log10(phi)));
    std::cout << "nmin=" << nmin << " nmax=" << nmax << std::endl;
    for (ull n = nmin; n <= nmax; n++) {
        double dlog_fib_approx = std::log10(c) +
                          n * std::log10(phi);
        ull ndigits = 1 + static_cast<ull>(std::floor(dlog_fib_approx));
        if (ndigits == 1000) {
            std::cout<< n << std::endl;
            return 0;
        }
    }

    std::cout << "No solution found" << std::endl;
/*
    for(ull n = 1; n <= nmax; ++n) {
        double dfib = c * (std::pow(phi, n) - std::pow(psi, n));
        ull nfib = static_cast<int>(std::floor(dfib));
        double dlog_fib = std::log10(c) +
                          n * std::log10(phi) +
                          std::log10(1 - std::pow(psi / phi, n));
        double dlog_fib_approx = std::log10(c) +
                          n * std::log10(phi);
        std::cout << n << " " 
                  << fib_seq[n] << " " 
                  << nfib << " "
                  << 1 + static_cast<ull>(std::floor(std::log10(fib_seq[n]))) << " "
                  << 1 + static_cast<ull>(std::floor(dlog_fib)) << " "
                  << 1 + static_cast<ull>(std::floor(dlog_fib_approx)) << " "
                  << std::endl; 
    }
*/

    return 0;
}
