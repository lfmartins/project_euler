// problem011.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 011" << std::endl;
    
    std::ifstream file("src/problem011.txt");
    std::string line;
    std::vector<std::vector<ull>> table;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<ull> row;
        ull num;
        while (iss >> num) {
            row.push_back(num);
        }
        table.push_back(row);
    }

    file.close();

    size_t nrows = table.size();
    size_t ncols = table[0].size();
    
    ull max_prod = 0;
    ull prod = 0;

    // Horizontal products
    for (size_t i = 0; i < nrows; ++i)
        for (size_t j = 0; j < ncols - 4; ++j)
            if (j < ncols - 4) {
                prod = table[i][j] * table[i][j + 1] * table[i][j + 2] * table[i][j + 3];
                if (prod > max_prod)
                     max_prod = prod;
            }
    // Vertical products
    for (size_t i = 0; i < nrows - 4; ++i)
        for (size_t j = 0; j < ncols; ++j)
            if (j < ncols - 4) {
                prod = table[i][j] * table[i][j + 1] * table[i][j + 2] * table[i][j + 3];
                if (prod > max_prod)
                     max_prod = prod;
            }
    // Diagonal right products
    for (size_t i = 0; i < nrows - 4; ++i)
        for (size_t j = 0; j < ncols - 4; ++j)
            if (j < ncols - 4) {
                prod = table[i][j] * table[i + 1][j + 1] * table[i + 2][j + 2] * table[i + 3][j + 3];
                if (prod > max_prod)
                     max_prod = prod;
            }
    // Diagonal left products
    for (size_t i = 0; i < nrows - 4; ++i)
        for (size_t j = 4; j < ncols; ++j)
            if (j < ncols - 4) {
                prod = table[i][j] * table[i + 1][j - 1] * table[i + 2][j - 2] * table[i + 3][j - 3];
                if (prod > max_prod)
                     max_prod = prod;
            }

    std::cout << max_prod << std::endl;
    
    
    return 0;
}
