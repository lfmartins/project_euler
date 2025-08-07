// problem043.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <tools.h>

ull extract_value(std::vector<ull> digits, ull k) {
    return digits[k] * 100 + digits[k + 1] * 10 + digits[k + 2];
}

int main() {
    std::cout << "Solving Project Euler Problem 043" << std::endl;

    std::vector<ull> digits(10);
    for (size_t i = 0; i < 10; ++i) {
        digits[i] = i;
    }

    ull sum = 0;
    do {
        if (extract_value(digits, 1) % 2 == 0 &&
            extract_value(digits, 2) % 3 == 0 &&
            extract_value(digits, 3) % 3 == 0 &&
            extract_value(digits, 4) % 5 == 0 &&
            extract_value(digits, 5) % 7 == 0 &&
            extract_value(digits, 6) % 11 == 0 &&
            extract_value(digits, 7) % 17 == 0 
           ) {
            sum += number_from_digits(digits);
        }
    } while (std::next_permutation(digits.begin(), digits.end()));

    std::cout << "Solution: " << sum << std::endl;

    return 0;
}


//        for(size_t i = 0; i < 10; ++i) {
//            std::cout << digits[i];
//        }
//        std::cout << std::endl;
//        if (++count > 20) {
//            break;
//        } 
