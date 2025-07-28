// problem017.cpp
#include <iostream>
#include <algorithm>
#include <tools.h>
    
std::string small_numbers[] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
};

std::string tens[] = {
    "dummy",
    "dummy",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
};

std::string number_phrase(ull n) {
    std::string tens_part;
    ull t = n % 100;
    if (t < 20) {
        tens_part = small_numbers[t];
    } else {
        ull tens_digit = t / 10;
        ull ones_digit = t % 10;
        tens_part = tens[tens_digit];
        if (ones_digit > 0) {
            tens_part += "-" + small_numbers[ones_digit];
        }
    }

    if (n < 100) {
       return tens_part;
    }

    ull h = n / 100;
    std::string phrase = small_numbers[h] + " hundred";

    if (t > 0) {
        phrase += " and " + tens_part;
    }

    return phrase;
}

int main() {
    std::cout << "Solving Project Euler Problem 017" << std::endl;
    
    ull nmax = 1000;
    ull sum = 0;
    for (ull n = 1; n < nmax; ++n) {
        std::string phrase = number_phrase(n);
        phrase.erase(std::remove_if(phrase.begin(), phrase.end(),
                                [](char c) { return c == ' ' || c == '-'; }),
                 phrase.end());
        sum += phrase.size();
    }
    std::string one_thousand = "onethousand";
    sum += one_thousand.size();

    std::cout << sum << std::endl;

    return 0;
}
