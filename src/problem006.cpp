#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 006" << std::endl;
    long long n = 100;
    std::vector<long long> numbers = range(1, n + 1);
    std::vector<long long> squares;
    for (long long i: numbers)
        squares.push_back(i * i);
    long long r = power(sum(numbers), 2) - sum(squares);
    std::cout << r << std::endl;
    return 0;
}
