#include <iostream>
#include "../mathlib/prime.h"

int main() {
	PrimeSieve primes;
	
	bool goldbach;
	unsigned i = 35;
	unsigned root, doublesquare;

	while(true) {
		if(primes.isPrime(i)) {
			i += 2;
			continue;
		}

		goldbach = false;
		root = 1;
		doublesquare = 2 * root * root;

		while(doublesquare < i) {
			if(primes.isPrime(i - doublesquare)) {
				goldbach = true;
				break;
			}
			
			++root;
			doublesquare = 2 * root * root;
		}

		if(!goldbach) break;

		i += 2;
	}

	std::cout << i << std::endl;

	return 0;
}
