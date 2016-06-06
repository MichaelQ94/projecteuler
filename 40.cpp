#include <iostream>
#include "../mathlib/mathlib.h"
#define MAX 1000000

int main() {
	char frac[MAX];
	unsigned count = 1;
	unsigned n = 0, digits = 0;
	for(int i = 0; i < MAX; ++i) {
		if(digits == 0) {
			n = count;
			++count;
			digits = Math::countdigits(n);
		}
		frac[i] = n / Math::pow(10, digits - 1);
		n %= Math::pow(10, digits - 1);
		--digits;
	}

	unsigned total = 1;
	for(int i = 1; i <= MAX; i *= 10) {
		total *= frac[i - 1];
	}

	std::cout << total << std::endl;
	return 0;
}
