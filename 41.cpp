#include <iostream>
#include "../mathlib/algorithm.h"
#include "../mathlib/prime.h"
#include <ctime>

unsigned buildNumber(std::vector<unsigned>&);

int main() {
	std::clock_t start;

	std::cout << "Loading primes... " << std::endl;;
	start = std::clock();
	ESieve p(87654321);
	std::cout << "Done (" << ((std::clock() - start) / (double) CLOCKS_PER_SEC) << ")." << std::endl;
	
	std::vector<unsigned> digits;
	std::vector<std::vector<unsigned> > perms;
	unsigned num, max = 0;

	for(unsigned i = 1; i <= 8; ++i) {
		digits.push_back(i);

		std::cout << "Generating permutations for 1 through " << i << "... " << std::endl;
		start = std::clock();
		perms = Math::permutations(digits);
		std::cout << "Done (" << ((std::clock() - start) / (double) CLOCKS_PER_SEC) << ")." << std::endl;
		
		std::cout << "Checking primality of " << i << "-digit pandigitals... " << std::endl;
		start = std::clock();
		for(unsigned j = 0; j < perms.size(); ++j) {
			num = buildNumber(perms[j]);
			if(p.isPrime(num) && num > max)
				max = num;
		}
		std::cout << "Done (" << ((std::clock() - start) / (double) CLOCKS_PER_SEC) << ")." << std::endl;
	}

	std::cout << max << std::endl;

	return 0;
}

unsigned buildNumber(std::vector<unsigned> &digits) {
	unsigned place = 1;
	unsigned num = 0;
	for(unsigned i = 0; i < digits.size(); ++i) {
		num += place * digits[i];
		place *= 10;
	}
	return num;
}
