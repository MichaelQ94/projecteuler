#include <iostream>
#include "../mathlib/algorithm.h"

typedef unsigned (*PolyFunc)(unsigned);

struct Polygonal {
	std::vector<unsigned> numbers;
	PolyFunc func;
	unsigned n;

	Polygonal(PolyFunc function) : func(function), n(1) { numbers.push_back(1); }
	unsigned next();
	void extendList(unsigned);
	bool isPolygonal(unsigned);

};

unsigned triangleFunc(unsigned n) { return (n * (n + 1)) / 2; }
unsigned pentagonalFunc(unsigned n) { return (n * ((3 * n) - 1)) / 2; }
unsigned hexagonalFunc(unsigned n) { return n * ((2 * n) - 1); }

int main() {
	const int INIT = 40755;
	Polygonal triangulars(&triangleFunc);
	Polygonal pentagonals(&pentagonalFunc);
	Polygonal hexagonals(&hexagonalFunc);

	triangulars.extendList(INIT);
	pentagonals.extendList(INIT);
	hexagonals.extendList(INIT);

	unsigned tnum;

	do {
		tnum = triangulars.next();
	} while(!(pentagonals.isPolygonal(tnum) && hexagonals.isPolygonal(tnum)));

	std::cout << tnum << std::endl;

	return 0;
}

unsigned Polygonal::next() {
	++n;
	numbers.push_back(func(n));
	return numbers.back();
}

void Polygonal::extendList(unsigned num) {
	while(num > numbers.back())
		next();
}

bool Polygonal::isPolygonal(unsigned num) {
	extendList(num);
	return Math::binary_search(numbers, num);
}
