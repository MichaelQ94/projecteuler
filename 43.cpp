#include <iostream>
#include <vector>
#include "../mathlib/algorithm.h"

unsigned primes[] = {2, 3, 5, 7, 11, 13, 17};

bool filter(const std::vector<unsigned>&);
unsigned build3DigitNumber(const std::vector<unsigned>&, unsigned pos);
unsigned buildNumber(const std::vector<unsigned>&);

int main() {
	std::vector<unsigned> digits;
	for(int i = 0; i <= 9; ++i) {
		digits.push_back(i);
	}

	std::vector<std::vector<unsigned> > pandigitals = Math::permutations(digits);
	pandigitals = Math::filter<std::vector<unsigned> >(pandigitals, &filter);

	unsigned long long sum = 0;

	for(unsigned i = 0; i < pandigitals.size(); ++i) {
		sum += static_cast<unsigned long long>(buildNumber(pandigitals[i]));
	}

	std::cout << sum << std::endl;

	//std::vector<unsigned> p{1, 4, 0, 6, 3, 5, 7, 2, 8, 9};
	//std::cout << buildNumber(p) << std::endl;
	//std::cout << filter(p) << std::endl;

	return 0;
}

bool filter(const std::vector<unsigned> &number) {
	bool ret = number[0] != 0;

	for(unsigned i = 1; i <= 7; ++i) {
		ret = ret && (build3DigitNumber(number, i) % primes[i - 1] == 0);
	}

	return ret;
}

unsigned build3DigitNumber(const std::vector<unsigned> &list, unsigned pos) {
	unsigned num = 0;
	for(unsigned place = 100; place > 0; place /= 10) {
		num += place * list[pos];
		
		++pos;
	}

	return num;
}

unsigned buildNumber(const std::vector<unsigned> &list) {
	unsigned num = 0, place = 1000000000;
	for(unsigned i = 0; i < list.size(); ++i) {
		num += place * list[i];

		place /= 10;
	}

	return num;
}
