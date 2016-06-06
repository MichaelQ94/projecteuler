#include <iostream>
#include "../mathlib/prime.h"
#include "../mathlib/mathlib.h"

unsigned countdigits(unsigned);
unsigned rotate(unsigned);
bool isCircular(unsigned);

PrimeSieve primes(1000000);

int main() {
	unsigned num = 0;
	for(unsigned i = 0; i < primes.size(); ++i) {
		std::cout << primes[i] << ": ";

		if(isCircular(primes[i])) {
			std::cout << "no";
			++num;
		}
		else {
			std::cout << "yes";
		}

		std::cout << std::endl;
	}
	std::cout << num << std::endl;
	return 0;
}

unsigned countdigits(unsigned n) {
	unsigned digits = 1;
	while(n /= 10) {
		++digits;
	}
	return digits;
}

unsigned rotate(unsigned n) {
	unsigned ones = n % 10;
	return (n / 10) + (ones * Math::pow(10, countdigits(n) - 1));
}

bool isCircular(unsigned n) { //input must be prime
	unsigned d = countdigits(n);
	for(unsigned i = 1; i < d; ++i) {
		n = rotate(n);
		if(!primes.isPrime(n)) {
			return false;
		}
	}

	return true;
}
