// problem019.cpp
#include <iostream>
#include <tools.h>

int main() {
    std::cout << "Solving Project Euler Problem 019" << std::endl;

    std::vector<ull> days_in_month = {
        31, // January
        28, // February
        31, // March
        30, // April 
        31, // May
        30, // June
        31, // July
        31, // August
        30, // September
        31, // October
        30, // November
        31, // December
    };

     // Jan 1st 1900 is a Monday
    ull day = 1;
    // Find which day is Jan 1st 1901
    // Notice 1900 is *not* a leap year
    day = (day + 365) % 7;

    // Count sundays.
    // Notice 2000 *is* a leap year.
    ull sundays = (day == 0) ? 1 : 0;
    for (ull year = 1901; year <= 2000; ++year) {
        for (ull month = 0; month < 12; ++month) {
            day = (day + days_in_month[month]) % 7;
            if (month == 1 && (year % 4 == 0)) {
                day = (day + 1) % 7;
            }
            if (day == 0) {
                ++sundays;
            }
        }
    }

    std::cout << "Solution: " << sundays << std::endl;
 
    return 0;
}
