// problem018.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 018" << std::endl;

    std::vector<std::vector<ull>> pyramid;

    std::ifstream file("data/problem018.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    std::string line;
    while(std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<ull> buffer;
        ull k;
        while(ss >> k) {
            buffer.push_back(k);
        }
        pyramid.push_back(buffer);
    }

    std::vector<std::vector<ull>> pyramid_max;
    for (ull i = 0; i < pyramid.size(); ++i) {
        pyramid_max.push_back(std::vector<ull>(pyramid[i].size(), 0));
    }

    pyramid_max[0][0] = pyramid[0][0];
    for (ull i = 1; i < pyramid_max.size(); ++i) {
        pyramid_max[i][0] = pyramid_max[i-1][0] + pyramid[i][0];
        ull jbound = pyramid_max[i].size();
        for (ull j = 1; j < jbound - 1; ++j) {
            ull sum_left = pyramid_max[i-1][j-1] + pyramid[i][j];
            ull sum_up = pyramid_max[i-1][j] + pyramid[i][j];
            pyramid_max[i][j] = sum_left > sum_up ? sum_left : sum_up;
        }
        pyramid_max[i][jbound - 1] = pyramid_max[i-1][jbound - 2] + pyramid[i][jbound - 1];
    }

    ull max = 0;
    std::vector<ull> last_row = pyramid_max[pyramid_max.size() - 1];
    for (ull j = 0; j < last_row.size(); ++j) {
        ull v = last_row[j];
        if (v > max) {
            max = v;
        }
    }

    std::cout << "Solution: " << max << std::endl;

    return 0;
}
