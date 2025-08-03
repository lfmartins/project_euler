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

// Problem 26 need to organize this
// Returns the decimal representation of p / q
//std::string decimal_repr(ull p, ull q) {
//    ull int_part = p / q;
//    std::string dr = std::format("{}.", int_part);
//
//    ull r = p % q;
//    std::vector<ull> dvec;
//    ull start = 0;
//    bool done = false;
//    while(true) {
//        std::vector<ull> rvec;
//        ull d = 10 * r / q;
//        r = 10 * r % q;
//        for(size_t i = 0; i < rvec.size(); ++i) {
//            if (rvec[i] == r) { //dvec[i] == d && 
//                start = i;
//                done = true;
//                break;
//            }
//        }
//        if (done) {
//            break;
//        }
//        dvec.push_back(d);
//        rvec.push_back(r);
//    }
//
//    for(std::size_t i = 0; i < start; ++i) {
//        dr += static_cast<char>('0' + dvec[i]);
//    }
//    dr += '(';
//    for(std::size_t i = start; i < dvec.size(); ++i) {
//        dr += static_cast<char>('0' + dvec[i]);
//    }
//    dr += ')';
//
//    return dr;
//}
//

//    for(ull q = 1; q <= 1000; ++ q) {
//        std::string dr = decimal_repr(p, q);
////        double d = static_cast<double>(p) / static_cast<double>(q);
//        std::regex pattern(R"(\[([^\]]*)\])");
//        std::smatch match;
//        std::string repeating;
//        if (std::regex_search(dr, match, pattern)) {
//            repeating = match[1];
//        } else {
//            std::cout << "Error: no match" << std::endl;
//            return 1;
//        }
//        std::cout << "q= " << q 
//                  << " size=" << repeating.size() 
//                  << " repeating=" << repeating 
//                  << std::endl;
//    }
    
//    std::vector<std::pair<ull, ull>> test_cases = {
//        {1, 2},
//        {1, 3},
//        {1, 7},
//        {20, 6},
//        {2, 5},
//        {17, 13},
//    };
//
//    for (auto [p, q]: test_cases) {
//        std::string dr = decimal_repr(p, q);
//        double d = static_cast<double>(p) / static_cast<double>(q);
//        std::cout << std::format("p={} q={} dr={} double={:.17}", p, q, dr, d) << std::endl;
//    }
//
//
//    std::cout << "Solving Project Euler Problem 026" << std::endl;
//
//    ull max_length = 0;
//    for (ull q = 2; q <= 100; ++q) {
//        ull length = repeating_length(q);
//        if (length > max_length) {
//            max_length = length;
//            std::cout << "q=" << q 
//                      << std::setprecision(30) << " " << 1.0 / q
//                      << " max_so_far=" << max_length << std::endl;
//        }
//    }
//
//    std::cout << max_length << std::endl;
//
/*
        ull length = repeating_length(q);
        std::cout << "q=" << std::setprecision(20) << 1.0 / q 
                  << " length=" << length << std::endl;
*/
