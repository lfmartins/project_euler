// tools.cpp
//

#include <iostream>
#include <algorithm>
#include <tools.h>

// Initialization of primes_base array
long long primes_limit = 1000000;
std::vector<long long> primes_base = sieve(primes_limit);
long long max_prime = primes_base.back();

long long flsqrt(long long n) {
    if (n < 0) {
        return -1;
    }

    if (n == 0 || n == 1) {
        return n;
    }

    long long x = n / 2;
    while (true) {
        long long new_x = (x + n / x) / 2;
        if (new_x >= x)
            return x;
        x = new_x;
    }
}

std::vector<long long> sieve(long long limit) {
    std::vector<long long> primes;

    if (limit < 2) {
        return primes;
    }

    std::vector<bool> is_prime(limit + 1, true);

    is_prime[0] = false;
    is_prime[1] = false;

    for (long long p = 2; p * p <= limit; ++p) {
        if (is_prime[p]) {
            for (long long multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    for (long long p = 2; p <= limit; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

std::vector<fterm> factor(long long n) {
    std::vector<fterm> factors;

    if (n == 0) {
        factors.push_back(fterm{0, 1});
        return factors;
    }

    if (n == 1) {
        factors.push_back(fterm{1, 1});
        return factors;
    }

    long long left = n;
    for (long long p : primes_base) {
        if (p * p > n) {
            if (left > 1) {
                factors.push_back(fterm{left, 1});
            }
            break;
        }
        int e = 0;
        long long rem = n % p;
        while (rem == 0) {
            e++;
            left /= p;
            rem = left % p;
        }
        if (e != 0) {
            factors.push_back(fterm{p, e});
        }
    }
    
    return factors;
}

std::vector<int> digits_from_number(long long n, int base) {
    if (n == 0)
        return std::vector<int> {0};
    std::vector<int> digits;
    while (n > 0) {
        digits.push_back(n % base);
        n = n / base;
    }
    std::reverse(digits.begin(), digits.end());
    return digits;
}

long long number_from_digits(std::vector<int> digits, int base) {
    long long n = 0;
    for (int d: digits) {
        n = base * n + d;
    }
    return n;
}

long long gcd(long long a, long long b) {
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    if (a < b) {
        long long t = a;
        a = b;
        b = t;
    }

    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }

    return a;
}

long long gcd(std::vector<long> numbers) {
    long long g = 0;
    for (long long i: numbers)
        g = gcd(g, i);
    return g;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

long long lcm(std::vector<long long> numbers) {
    long long l = 1;
    for (long long i: numbers)
        l = lcm(l, i);
    return l;
}

long long power(long long n, int e) {
    long long result = 1;
    while (e > 0) {
        if (e % 2 == 1)
            result *= n;
        n *= n;
        e /= 2;
    }
    return result;
}

std::vector<long long> range(long long a, long long b) {
    std::vector<long long> rng;
    for (long long i = a; i < b; ++i)
        rng.push_back(i);
    return rng;
}

long long sum(std::vector<long long> numbers) {
    long long s = 0;
    for (long long i: numbers)
        s += i;
    return s;
}

std::vector<triple<long long>> pythagorean_triples(long long cmax) {
    std::vector<triple<long long>> triples;
    for (long long m = 2; m <= flsqrt(cmax); ++m) {
        for (long long n = 1; n < m; ++n) {
            if ( (gcd(m, n) == 1) && (m % 2 == 0 || n % 2 ==0)) {
                long long a = m * m - n * n;
                long long b = 2 * m * n;
                long long c = m * m + n * n;
                if (c > cmax)
                    return triples;
                triples.push_back(triple{a, b, c});
            }
        }
    }
    return triples;
}
