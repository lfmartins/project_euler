#include <iostream>

int main() {
    long long f1 = 1, f2 = 2;
    long long sum = 0;

    while (f2 <= 4000000L) {
        if (f2 % 2 == 0) {
            sum += f2;
        }
        long long f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    
    std::cout << sum << std::endl;

    return 0;
}
