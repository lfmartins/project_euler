// problem029.cpp
#include <iostream>
#include "tools.h"

bool check_previous(const factorization& afact, ull b, const factorization& cfact, ull limit) {
    if (afact.size() != cfact.size())
        return false;
    for (size_t i = 0; i < afact.size(); ++ i)
        if (afact[i].p != cfact[i].p) 
            return false;
    if (afact[0].e * b % cfact[0].e != 0)
        return false;
    ull d = afact[0].e * b / cfact[0].e;
    if (d > limit)
        return false;
    for (size_t i = 1; i < afact.size(); ++i)
        if (afact[i].e * b != cfact[i].e * d)
            return false;
    return true;
}

int main() {
    std::cout << "Solving Project Euler Problem 029" << std::endl;

    ull limit = 100;
    ull count = 0;
    for (ull a = 2; a <= limit; ++a) {
        factorization afact = factor(a);
        for (ull b = 2; b <= limit; ++b) {
            bool counted = false;
            for (ull c = 2; c < a; ++c) {
                factorization cfact = factor(c);
                counted = check_previous(afact, b, cfact, limit);
                if (counted)
                    break;
            }
            if (!counted)
                ++count;
        }
    }

    std::cout << "Solution: " << count << std::endl;

    return 0;
}
