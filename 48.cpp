#include <iostream>

const unsigned long long BASE = 10000000000;

unsigned long long modexp(unsigned, unsigned, unsigned long long);

unsigned long long modsum(unsigned long long, unsigned long long, unsigned long long);

int main() {
	unsigned long long sum = 0;

	for(int i = 1; i <= 1000; ++i)
		sum = modsum(sum, modexp(i, i, BASE), BASE);

	std::cout << sum << std::endl;

	return 0;
}

unsigned long long modexp(unsigned num, unsigned pow, unsigned long long base) {
	unsigned long long ret = 1;
	num %= base;

	while(pow > 0) {
		ret *= num;
		ret %= base;
		--pow;
	}

	return ret;
}

unsigned long long modsum(unsigned long long a, unsigned long long b, unsigned long long base) {
	return (a + b) % base;
}
