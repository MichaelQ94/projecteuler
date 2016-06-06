#include <iostream>
#include "../mathlib/algorithm.h"

struct Pentagonals {
	std::vector<unsigned> pentagonals;
	unsigned max, d;

	Pentagonals() : max(2) { pentagonals.push_back(1); pentagonals.push_back(5); }
	void extendList(unsigned);
	bool isPentagonal(unsigned);
	void findtheD();
	void findtheDifference();
	void findMinD();
	bool pentagonalSD(unsigned, unsigned);
};

int main() {
	Pentagonals p;

	p.findtheD();
	std::cout << p.d << std::endl;
	p.findtheDifference();
	std::cout << p.pentagonals[p.pentagonals.size() - 1] << std::endl;
	std::cout << p.pentagonals.size() << std::endl;
	p.findMinD();

	return 0;
}

void Pentagonals::extendList(unsigned n) {
	while(n > pentagonals[pentagonals.size() - 1]) {
		++max;
		pentagonals.push_back((max * ((3 * max) - 1)) / 2);
	}
}

bool Pentagonals::isPentagonal(unsigned n) {
	extendList(n);
	return Math::binary_search(pentagonals, n);
}

bool Pentagonals::pentagonalSD(unsigned n, unsigned m) {
	return isPentagonal(n + m) && isPentagonal(n - m);
}

void Pentagonals::findtheD() {
	for(unsigned i = 1; ; ++i) {
		for(int j = i - 1; j >= 0; --j) {
			if(pentagonalSD(pentagonals[i], pentagonals[j])) {
				d = pentagonals[i] - pentagonals[j];
				return;
			}
		}
	}
}

void Pentagonals::findtheDifference() {
	while(d < pentagonals[pentagonals.size() - 1] - pentagonals[pentagonals.size() - 2]) {
		++max;
		pentagonals.push_back((max * ((3 * max) - 1)) / 2);
	}
}

void Pentagonals::findMinD() {
	unsigned size = pentagonals.size();
	for(unsigned i = 1; i < size; ++i) {
		for(int j = i - 1; j >= 0; --j) {
			if(pentagonals[i] - pentagonals[j] >= d)
				break;
			else if(pentagonalSD(pentagonals[i], pentagonals[j]))
				d = pentagonals[i] - pentagonals[j];
		}
	}

	std::cout << d << std::endl;
}
