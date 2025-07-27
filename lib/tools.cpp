// tools.cpp

#include <iostream>
#include <algorithm>
#include <tools.h>

// Initialization of primes_base array
ull primes_limit = 1000000;
std::vector<ull> primes_base = sieve(primes_limit);
ull max_prime = primes_base.back();

ull flsqrt(ull n) {
    if (n == 0 || n == 1) {
        return n;
    }

    ull x = n / 2;
    while (true) {
        ull new_x = (x + n / x) / 2;
        if (new_x >= x)
            return x;
        x = new_x;
    }
}

std::vector<ull> sieve(ull limit) {
    std::vector<ull> primes;

    if (limit < 2) {
        return primes;
    }

    std::vector<bool> is_prime(limit + 1, true);

    is_prime[0] = false;
    is_prime[1] = false;

    for (ull p = 2; p * p <= limit; ++p) {
        if (is_prime[p]) {
            for (ull multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    for (ull p = 2; p <= limit; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

std::vector<fterm> factor(ull n) {
    std::vector<fterm> factors;

    if (n == 0) {
        factors.push_back(fterm{0, 1});
        return factors;
    }

    if (n == 1) {
        factors.push_back(fterm{1, 1});
        return factors;
    }

    ull left = n;
    for (ull p : primes_base) {
        if (p * p > n) {
            if (left > 1) {
                factors.push_back(fterm{left, 1});
            }
            break;
        }
        ull e = 0;
        ull rem = n % p;
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

ull divisor_count(ull n) {
    ull count = 1;
    for (fterm ft: factor(n)) 
        count *= ft.e + 1;
    return count;
}
   
std::vector<ull> digits_from_number(ull n, ull base) {
    if (n == 0)
        return std::vector<ull> {0};
    std::vector<ull> digits;
    while (n > 0) {
        digits.push_back(n % base);
        n = n / base;
    }
    std::reverse(digits.begin(), digits.end());
    return digits;
}

ull number_from_digits(std::vector<ull> digits, ull base) {
    ull n = 0;
    for (ull d: digits) {
        n = base * n + d;
    }
    return n;
}

ull gcd(ull a, ull b) {
    if (a == 0) {
        return b;
    }

    while (b != 0) {
        ull r = a % b;
        a = b;
        b = r;
    }

    return a;
}

ull gcd(std::vector<ull> numbers) {
    ull g = 0;
    for (ull i: numbers)
        g = gcd(g, i);
    return g;
}

ull lcm(ull a, ull b) {
    return (a / gcd(a, b)) * b;
}

ull lcm(std::vector<ull> numbers) {
    ull l = 1;
    for (ull i: numbers)
        l = lcm(l, i);
    return l;
}

ull power(ull n, ull e) {
    ull result = 1;
    while (e > 0) {
        if (e % 2 == 1)
            result *= n;
        n *= n;
        e /= 2;
    }
    return result;
}

std::vector<ull> ull_range(ull a, ull b) {
    std::vector<ull> rng;
    for (ull i = a; i < b; ++i)
        rng.push_back(i);
    return rng;
}

ull ull_sum(std::vector<ull> values) {
    ull s = 0;
    for (ull i: values)
        s += i;
    return s;
}

std::vector<triple<ull>> pythagorean_triples(ull cmax) {
    std::vector<triple<ull>> triples;
    for (ull m = 2; m <= flsqrt(cmax); ++m) {
        for (ull n = 1; n < m; ++n) {
            if ( (gcd(m, n) == 1) && (m % 2 == 0 || n % 2 ==0)) {
                ull a = m * m - n * n;
                ull b = 2 * m * n;
                ull c = m * m + n * n;
                if (c > cmax)
                    return triples;
                triples.push_back(triple{a, b, c});
            }
        }
    }
    return triples;
}
