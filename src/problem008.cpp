// problem008.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 008" << std::endl;

    std::ifstream file("data/problem008.txt");
    std::string line, digits_str;
    while(std::getline(file, line)) {
        digits_str += line;
    }

    std::vector<int> digits(digits_str.size());
    for (size_t i = 0; i < digits_str.size(); ++i)
        digits[i] = digits_str[i] - '0';
    
    size_t length = 13;
    ull max_prod = 0;
    for (size_t i = 0; i < digits.size() - length; ++i) {
        ull prod = 1;
        for (size_t j = 0; j < length; ++j)
            prod *= digits[i + j];
        if (prod > max_prod)
            max_prod = prod;
    }
    std::cout << max_prod << std::endl;

    return 0;
}
