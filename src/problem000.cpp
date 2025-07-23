// problem000.cpp
//

#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Test tools.cpp" << std::endl;
/*    
    // Test square root
    for (long long n=1; n <= 10000000LL; ++n) {
        long long k = flsqrt(n);
        long long blow = k * k;
        long long bhigh = (k + 1) * (k + 1);
        if (! (blow <= n && bhigh > n)) {
            std::cout << "Error: n=" << n 
                << " k=" << k 
                << " blow=" << blow 
                << " bhigh=" << bhigh 
                << std::endl;
            return 1;
        }
    }

    std::cout << "No errors in integer square root\n" << std::endl;
*/
/*
    std::cout << "Primes limit: " << primes_limit << std::endl;
    std::cout << "Size of primes_base: " << primes_base.size() << std::endl;
    std::cout << "Largest prime in primes_base: " << max_prime << std::endl;
*/
/*
    long long n = 2 * 2 * 3 * 3 * 3 * 7 * 11 * 11 * 101;
    std::vector<fterm> factors = factor(n);

    std::cout << "Factorization of " << n << std::endl;
    for (fterm f :factors) {
        std::cout << "(" << f.p << "," << f.e << ") ";
    }
    std::cout << std::endl;


*/
/*
    long long n = 1939283883;
    std::vector<int> digits = digits_from_number(n, 2);
    std::cout << n << " ";
    for (int d: digits) {
        std::cout << d << " ";
    }
    std::cout << std::endl;
    long long n1 = number_from_digits(digits, 2);  
    std::cout << n1 << std::endl; 
    return 0;
*/
/*
    long long a = power(2, 3) * power(3, 4) * power(13, 1), 
              b = power(2, 2) * power(3, 1) * power(11, 1) * power(13, 3),
              g = power(2, 2) * power(3, 1) * power(13, 1),
              l = power(2, 3) * power(3, 4) * power(11, 1) * power(13, 3);

    std::cout << "a= " << a << " b=" << b << " g=" << g << " l=" << l 
              << " gcd(a,b)=" << gcd(a,b)  
              << " lcm(a,b)=" << lcm(a,b)
              << std::endl;
*/
/*
    std::cout << "Computing pythagorean triples" << std::endl;
    long long cmax = 100;
    std::vector<triple<long long> > triples;
    triples = pythagorean_triples(cmax);
    std::cout << "Number of triples found: " << triples.size() << std::endl;
    for (triple<long long> t: triples)
        std::cout << "(" << t.a << ", " << t.b << ", " << t.c << ")" << std::endl;
*/
    long long n = 10;
    long long ndivs = divisor_count(n);
    std::cout << n << " " << ndivs << std::endl;

}
