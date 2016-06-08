#include <iostream>
#include <vector>
#include "../mathlib/prime.h"

bool same_digits(unsigned, unsigned);

int main() {
	PrimeSieve primes(10000);
	std::vector<unsigned> fourDigitPrimes;

	for(unsigned i = 1000; i <= 9999; ++i)
		if(primes.isPrime(i))
			fourDigitPrimes.push_back(i);
	
	unsigned first, second, third;
	for(size_t i = 0; i < fourDigitPrimes.size(); ++i) {
		first = fourDigitPrimes[i];

		for(unsigned j = 1; first + (2 * j) <= 9999; ++j) {
			second = first + j;
			third = second + j;

			if(same_digits(first, second) && same_digits(second, third)
				&& primes.isPrime(second) && primes.isPrime(third))

				std::cout << first << second << third << std::endl;
		}
	}

	return 0;
}

bool same_digits(unsigned a, unsigned b) {
	bool a_digits[10];
	bool b_digits[10];

	for(unsigned i = 0; i < 10; ++i) {
		a_digits[i] = false;
		b_digits[i] = false;
	}

	if(a == 0)
		a_digits[0] = true;
	if(b == 0)
		b_digits[0] = true;
	
	while(a) {
		a_digits[a % 10] = true;
		a /= 10;
	}
	while(b) {
		b_digits[b % 10] = true;
		b /= 10;
	}

	for(unsigned i = 0; i < 10; ++i)
		if(a_digits[i] != b_digits[i])
			return false;
	
	return true;
}
