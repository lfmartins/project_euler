// problem013.cpp
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <tools.h>

using namespace boost::multiprecision;

int main() {
    std::cout << "Solving Project Euler Problem 013" << std::endl;

    std::ifstream file("data/problem013.txt");
    std::vector<std::string> lines;
    std::string line;

    cpp_int sum = 0;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            cpp_int num(line);
            sum += num;
        }
    }

    file.close();

    std::string digits = sum.str().substr(0, 10);

    std::cout << "Solution: " << digits << std::endl;
	
    return 0;
}
