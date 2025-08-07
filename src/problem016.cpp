// problem016.cpp
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <tools.h>

using boost::multiprecision::cpp_int;

int main() {
    cpp_int base(2);
    ull n = 1000;
    cpp_int p = mp_power(base, n);
    cpp_int sum = 0;

    while (p > 0) {
        sum += p % 10;
        p /= 10;
    }
        
    std::cout << "Solution: " << sum << std::endl;

    return 0;
}
