// tools.h

#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

using ll = long long;
using ull = unsigned long long;

// Initial vector of primes
extern ull primes_limit;
extern std::vector<ull> primes_base;
extern ull max_prime;

// Factoriztion term: p = prime factor, e = exponent
struct fterm {
    ull p;
    ull e;
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

// Compute floor of square root of n
ull flsqrt(ull n);

// Find prime numbers up to limit
std::vector<ull> sieve(ull limit);

// Factor number n
std::vector<fterm> factor(ull n);

// Find the number of divisors of n
ull divisor_count(ull n);

// Find "digits" of a n in given base
std::vector<ull> digits_from_number(long long n, ull base = 10);

// Compute n from digits in given base
ull number_from_digits(std::vector<ull>, ull base = 10);

// GCD of two numbers
ull gcd(ull a, ull b);

// GCD of a vector of numbers
ull gcd(std::vector<ull> numbers);

// LCM of two numbers
ull lcm(ull a, ull b);

// LCM of a vector of numbers
ull lcm(std::vector<ull> numbers);

// Raise a number to a power mod m
ull power_mod(ull n, ull e, ull m);

// Raise a number to a power
ull power(ull n, ull e);


cpp_int mp_power(cpp_int n, ull e); 

// Range of values (as in Python)
std::vector<ull> ull_range(ull a, ull b);

// Sum of a vector of values
ull ull_sum(std::vector<ull> values);

// Pythagorean triples with c <= cmax
std::vector<triple<ull>> pythagorean_triples(ull cmax);

#endif // TOOLS_H
