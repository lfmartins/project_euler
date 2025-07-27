// problem006.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 006" << std::endl;
    ull n = 100;
    std::vector<ull> numbers = ull_range(1, n + 1);
    std::vector<ull> squares;
    for (ull i: numbers)
        squares.push_back(i * i);
    ull r = power(ull_sum(numbers), 2) - ull_sum(squares);
    std::cout << r << std::endl;
    return 0;
}
