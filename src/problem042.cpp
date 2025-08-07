// problem042.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 042" << std::endl;

    std::string file_name("data/0042_words.txt");
    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cerr << "Failed to open file " << file_name;
        return 1;
    }
    
    std::string line;
    ull count = 0;
    while(std::getline(file, line, ',')) {
        std::string word = line.substr(1, line.size()-2);
        ull score = 0;
        for (char c: word) {
            score += c - 'A' + 1;
        }

        for (ull n = 1;; ++n) {
            ull t = n * (n + 1) / 2;
            if (t < score) {
                continue;
            }
            if (t == score) {
                ++count;
            }
            break;
        }
    }

    std::cout << "Solution: " << count << std::endl;

    return 0;
}
