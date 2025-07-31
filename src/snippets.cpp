// snippets.cpp

// Problem 025
// Compute a bunch of Fibonacci numbers and store in an array
    ull nmax = 40;
    std::vector<ull> fib_seq(nmax + 1);
    fib_seq[0] = 0;
    fib_seq[1] = 1;
    for(ull n = 2; n <= nmax; ++n) {
        fib_seq[n] = fib_seq[n - 1] + fib_seq[n - 2];
    }
 
// Compute Fibonacci numbers using the formula.
// Also compute the number of digits of the Fibonacci
// numbers using different methods.
    double phi = (1 + std::sqrt(5)) / 2;
    double psi = (1 - std::sqrt(5)) / 2;
    double c = 1 / std::sqrt(5);

    for(ull n = 1; n <= nmax; ++n) {
        // Formula for Fibonacci numbers
        double dfib = c * (std::pow(phi, n) - std::pow(psi, n));
        ull nfib = static_cast<int>(std::floor(dfib));
        // log10 of Fibonacci numbers
        double dlog_fib = std::log10(c) +
                          n * std::log10(phi) +
                          std::log10(1 - std::pow(psi / phi, n));
        // log10 of Fibonacci numbers, approximation
        double dlog_fib_approx = std::log10(c) +
                          n * std::log10(phi);
        std::cout << "n=" << n << " " 
                  << "F(n)=" << fib_seq[n] << " " 
                  << "F(n)=" << nfib << " " // From formula
                  << "digits=" << 1 + static_cast<ull>(std::floor(std::log10(fib_seq[n]))) << " "
                  << "digits=" << 1 + static_cast<ull>(std::floor(dlog_fib)) << " "
                  << "digits=" << 1 + static_cast<ull>(std::floor(dlog_fib_approx)) << " "
                  << std::endl; 
    }
