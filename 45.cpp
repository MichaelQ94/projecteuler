#include <iostream>
#include "../mathlib/algorithm.h"
#include <cstddef>

unsigned triangleFunc(size_t n) { return (n * (n + 1)) / 2; }
unsigned pentagonalFunc(size_t n) { return (n * ((3 * n) - 1)) / 2; }
unsigned hexagonalFunc(size_t n) { return n * ((2 * n) - 1); }

int main() {
	const int INIT = 40755;
	Math::IncreasingSequence<unsigned> triangulars(&triangleFunc);
	Math::IncreasingSequence<unsigned> pentagonals(&pentagonalFunc);
	Math::IncreasingSequence<unsigned> hexagonals(&hexagonalFunc);

	triangulars.extend(INIT);
	pentagonals.extend(INIT);
	hexagonals.extend(INIT);

	unsigned tnum;

	do {
		tnum = triangulars.next();
	} while(!(pentagonals.contains(tnum) && hexagonals.contains(tnum)));

	std::cout << tnum << std::endl;

	return 0;
}
