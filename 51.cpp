#include <iostream>
#include <vector>
#include <unordered_set>
#include "../mathlib/prime.h"

unsigned replace_digits(unsigned, unsigned char, unsigned char);
std::vector<unsigned char> unique_digits(unsigned);
unsigned char first_digit(unsigned);

int main() {
	PrimeSieve primes(999999);
	std::unordered_set<unsigned> previousprimes;
	std::vector<unsigned char> uniquedigits;
	unsigned prime, test;
	unsigned char firstdigit, digit;
	unsigned char primecount;

	for(size_t i = 0; i < primes.size(); ++i) {
		prime = primes[i];

		if(!previousprimes.insert(prime).second)
			continue;

		uniquedigits = unique_digits(prime);
		firstdigit = first_digit(prime);

		for(size_t j = 0; j < uniquedigits.size(); ++j) {
			digit = uniquedigits[j];
			primecount = 0;

			for(unsigned char k = ((firstdigit == digit) ? 1 : 0); k < 10; ++k) {
				test = replace_digits(prime, digit, k);

				if(primes.isPrime(test)) {
						++primecount;

						if(primecount == 8) {
							std::cout << prime << std::endl;
							return 0;
						}
				}
			}
		}
	}

	return 0;
}

unsigned replace_digits(unsigned number, unsigned char val, unsigned char rval) {
	unsigned ret = 0;
	unsigned place = 1;
	do {
		ret += place * (((number % 10) == val) ? rval : (number % 10));
		number /= 10;
		place *= 10;
	} while(number);

	return ret;
}

std::vector<unsigned char> unique_digits(unsigned number) {
	bool digits[10];
	for(int i = 0; i < 10; ++i)
		digits[i] = false;
	
	do {
		digits[number % 10] = true;
		number /= 10;
	} while(number);

	std::vector<unsigned char> uniquedigits;
	for(int i = 0; i < 10; ++i)
		if(digits[i])
			uniquedigits.push_back(i);

	return uniquedigits;
}

unsigned char first_digit(unsigned number) {
	unsigned char ret;

	do {
		ret = number % 10;
		number /= 10;
	} while(number);

	return ret;
}
