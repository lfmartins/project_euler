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

bool is_square(ull n) {
    ull r = flsqrt(n);
    return r * r == n;
}

ull factorial(ull n) {
    if (n == 0) {
        return 1;
    }

    ull prod = 1;
    for (ull i = 2; i <= n; ++i) {
        prod *= i;
    }
    return prod;
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

bool is_prime(ull n) {
    if (n == 0 || n == 1) 
        return false;

    ull limit = flsqrt(n);
    for (ull i = 0; true; ++i) {
        ull p = primes_base[i];
        if (p > limit) {
            break;
        }
        if (n % p == 0) 
            return false;
    }
    return true;
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

ull divisors_count(ull n) {
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    ull count = 1;
    for (fterm ft: factor(n)) 
        count *= ft.e + 1;
    return count;
}

ull proper_divisors_count(ull n) {
    if (n == 0 || n == 1)
        return 0;

    return divisors_count(n) - 1;
}

ull divisors_sum(ull n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    ull ds = 1;
    for (fterm tf: factor(n)) {
        ds *= (ull_power(tf.p, tf.e + 1) - 1) / (tf.p -1);
    }
    return ds;
}

ull proper_divisors_sum(ull n) {
    if (n == 0 || n == 1)
        return 0;

    return divisors_sum(n) - n;
}

bool is_amicable_pair(ull m, ull n) {
    return proper_divisors_sum(m) == proper_divisors_sum(n);
}

bool is_perfect(ull n) {
    return proper_divisors_sum(n) == n;
}

bool is_abundant(ull n) {
    return proper_divisors_sum(n) > n;
}

bool is_deficient(ull n) {
    return proper_divisors_sum(n) < n;
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

ull power_mod(ull n, ull e, ull m) {
    cpp_int nn = n % m;
    ull result = 1;
    while (e > 0) {
        if (e % 2 == 1)
            result = static_cast<ull>((result * nn) % m);
        nn = (nn * nn) % m;
        e /= 2;
    }
    return result;
}

//long long mod_pow(long long a, long long b, long long m) {
//    a %= m;
//    long long result = 1;
//    while (b > 0) {
//        if (b % 2 == 1) result = (result * a) % m; // if b is odd
//        a = (a * a) % m;
//        b /= 2;
//    }
//    return result;
//}

ull ull_power(ull n, ull e) {
    ull result = 1;
    while (e > 0) {
        if (e % 2 == 1)
            result *= n;
        n *= n;
        e /= 2;
    }
    return result;
}

cpp_int mp_power(cpp_int n, ull e) {
    cpp_int result = 1;
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

bool is_palindromic(ull n, ull base) {
    std::vector<ull> digits = digits_from_number(n, base);

    for (size_t i = 0; i <= digits.size() / 2; ++i) {
        size_t j = digits.size() - i - 1;
        if (digits[i] != digits[j]) {
            return false;
        }
    }

    return true;
}

bool is_pandigital(ull n) {
    std::vector<ull> digits = digits_from_number(n);

    ull sz = digits.size();
    if (sz > 9) {
        return false;
    }

    std::vector<ull> digit_counts(sz, 0);

    for (ull d: digits) {
        if (d == 0 || d > sz) {
            return false;
        }
        ++digit_counts[d - 1];
    }
    for (ull c: digit_counts) {
        if (c != 1) {
            return false;
        }
    }

    return true;
}
