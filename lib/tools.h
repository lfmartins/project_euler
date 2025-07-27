// tools.h

#ifndef TOOLS_H
#define TOOLS_H

#include <vector>

using ll = long long;
using ull = unsigned long long;

// Initial vector of primes
extern long long primes_limit;
extern std::vector<long long> primes_base;
extern long long max_prime;

// Factoriztion term: p = prime factor, e = exponent
struct fterm {
    long long p;
    int e;
};

// Pair of values
template <typename T>
struct pair {
    T a;
    T b;
};

// Triple of values
template <typename T>
struct triple {
    T a;
    T b;
    T c;
};

// Factor number n
std::vector<fterm> factor(long long n);

// Find the number of divisors of n
long long divisor_count(long long n);

// Find prime numbers up to limit
std::vector<long long> sieve(long long limit);

// Compute floor of square root of n
long long flsqrt(long long n);

// Find "digits" of a n in given base
std::vector<int> digits_from_number(long long n, int base = 10);

// Compute n from digits in given base
long long number_from_digits(std::vector<int>, int base = 10);

// GCD of two numbers
long long gcd(long long a, long long b);

// GCD of a vector of numbers
long long gcd(std::vector<long> numbers);

// LCM of two numbers
long long lcm(long long a, long long b);

// LCM of a vector of numbers
long long lcm(std::vector<long long> numbers);

// Raise a number to a power
long long power(long long n, int e);

// Range of integers (as in Python)
std::vector<long long> range(long long a, long long b);

// Sum of a vector of numbers
long long sum(std::vector<long long> numbers);

// Pythagorean triples with c <= cmax
std::vector<triple<long long>> pythagorean_triples(long long cmax);

#endif // TOOLS_H
