#include <iostream>
#include "../mathlib/mathlib.h"

#define BASE 10

bool permuted_multiples(unsigned num);
void find_digits(unsigned num, bool digits[BASE]);

int main() {
    unsigned num = 100;
    while(true) {
        if(permuted_multiples(num))
            break;
        else
            ++num;
    }

    std::cout << num << std::endl;
    return 0;
}

bool permuted_multiples(unsigned num) {
    unsigned ndigits = Math::countdigits(num);
    unsigned bound = 1;
    for(unsigned d = 0; d < ndigits; ++d)
        bound *= 10;

    unsigned test = num * 6;
    if(test >= bound)
        return false;

    bool digits[BASE], testdigits[BASE];
    find_digits(num, digits);

    for(; test > num; test -= num) {
        find_digits(test, testdigits);
        
        for(int i = 0; i < BASE; ++i)
            if(digits[i] != testdigits[i])
                return false;
    }

    return true;
}

void find_digits(unsigned num, bool digits[BASE]) {
    for(int i = 0; i < BASE; ++i)
        digits[i] = false;
    
    do {
        digits[num % BASE] = true;
        num /= BASE;
    } while(num);
}

