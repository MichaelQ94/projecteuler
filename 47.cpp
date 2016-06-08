#include <iostream>
#include <vector>
#include <utility>
#include "../mathlib/prime.h"

void printPrimeFac(std::vector<std::pair<unsigned, unsigned> > &&);

int main() {
	PrimeSieve primes;

	unsigned num, i;

	for(num = 2; ; ++num) {
		for(i = 0; i < 4; ++i) {
			if(primes.prime_factorization(num + i).size() != 4)
				break;
		}

		if(i < 4)
			num += i;
		else
			break;
	}

	std::cout << num << std::endl;
	for(i = 0; i < 4; ++i)
		printPrimeFac(primes.prime_factorization(num + i));

	return 0;
}

void printPrimeFac(std::vector<std::pair<unsigned, unsigned> > &&primefactorization) {
	for(size_t i = 0; i < primefactorization.size(); ++i) {
		std::cout << '(' << primefactorization[i].first << ", "
			<< primefactorization[i].second << ") ";
	}
	std::cout << std::endl;
}
