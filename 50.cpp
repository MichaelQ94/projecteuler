#include <iostream>
#include "../mathlib/prime.h"

#define MAX 1000000

int main() {
	PrimeSieve primes(MAX);
	unsigned max = 1, maxprime;
	unsigned sum;

	for(size_t length = 6; length < primes.size(); ++length) {
		for(size_t i = 0; i + length <= primes.size(); ++i) {
			sum = 0;
			for(size_t j = 0; j < length; ++j) {
				sum += primes[i + j];
				if(sum >= MAX)
					break;
			}

			if(sum >= MAX)
				break;

			if(primes.isPrime(sum)) {
				max = length;
				maxprime = sum;
			}

		}
	}

	std::cout << maxprime << ' ' << max << std::endl;

	return 0;
}
