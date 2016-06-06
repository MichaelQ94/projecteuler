#include <iostream>
#include "../mathlib/mathlib.h"

unsigned digitfacsum(unsigned);

int main() {
	unsigned max = Math::fac(9) * 7;
	int sum = 0;
	for(unsigned i = 10; i <= max; ++i) {
		if(i == digitfacsum(i)) {
			sum += i;
			std::cout << i << std::endl;
		}
	}

	std::cout << sum << std::endl;
	return 0;
}

unsigned digitfacsum(unsigned n) {
	unsigned sum = 0;
	while(n) {
		sum += Math::fac(n % 10);
		n /= 10;
	}
	return sum;
}
