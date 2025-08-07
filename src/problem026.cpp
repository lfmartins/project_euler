// problem026.cpp
#include <iostream>
#include <format>
#include <regex>
#include <tools.h>

ull repeating_length(ull q) {
    ull r = 1;
    std::vector<ull> rvec;
    while(true) {
        r = 10 * r % q;
        for(size_t i = 0; i < rvec.size(); ++i) {
            if (rvec[i] == r) {
                return rvec.size() - i;
            }
        }
        rvec.push_back(r);
    }
}

int main() {
    ull max_length = 0;
    ull max_q;
    for (ull q = 1; q <= 1000; ++q) {
        ull length = repeating_length(q);
        if (length > max_length) {
            max_length = length;
            max_q = q;
        }
    }

    std::cout << "Solution: " << max_q << std::endl;

    return 0;
}
