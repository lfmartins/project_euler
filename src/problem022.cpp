// problem022.cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <tools.h>

ull alpha_score(std::string word) {
    ull score = 0;
    for (char c: word) {
        score += c - 'A' + 1;
    }
    
    return score;
}

int main() {
    std::cout << "Solving Project Euler Problem 022" << std::endl;

    std::ifstream file("data/0022_names.txt");

    if (!file.is_open()) {
        std::cerr << "Cannot open file" << std::endl;
        return 1;
    }

    std::string contents(
            (std::istreambuf_iterator<char>(file)),
            std::istreambuf_iterator<char>());
    std::stringstream ss(contents);
    std::string name;
    std::vector<std::string> names;

    while(std::getline(ss, name, ',')) {
        names.push_back(name.substr(1, name.size() - 2));
    }

    std::sort(names.begin(), names.end());

    ull sum = 0;
    for (size_t i = 0; i < names.size(); ++i) {
        sum += (i + 1) * alpha_score(names[i]);
    }

    std::cout << "Solution: " <<  sum << std::endl;

    return 0;
}
