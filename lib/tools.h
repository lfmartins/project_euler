// tools.h

#ifndef TOOLS_H
#define TOOLS_H

#include <vector>

struct fterm {
    long long p;
    int e;
};

template <typename T>
struct pair {
    T a;
    T b;
};

template <typename T>
struct triple {
    T a;
    T b;
    T c;
};

std::vector<fterm> factor(long long n);
std::vector<long long> sieve(long long limit);
long long flsqrt(long long n);

extern long long primes_limit;
extern std::vector<long long> primes_base;
extern long long max_prime;
std::vector<int> digits_from_number(long long n, int base = 10);
long long number_from_digits(std::vector<int>, int base = 10);
long long gcd(long long a, long long b); 
long long gcd(std::vector<long> numbers); 
long long lcm(long long a, long long b); 
long long lcm(std::vector<long long> numbers); 
long long power(long long n, int e);
std::vector<long long> range(long long a, long long b); 
long long sum(std::vector<long long> numbers);  
std::vector<triple<long long>> pythagorean_triples(long long cmax);

#endif // TOOLS_H
