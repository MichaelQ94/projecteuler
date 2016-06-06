#include <iostream>
#include "../mathlib/rational.h"

bool isCurious(Rational);

int main() {
	Rational product(1);
	Rational r(0);

	for(unsigned d = 11; d < 100; ++d) {
		r.setD(d);
		for(unsigned n = 10; n < d; ++n) {
			r.setN(n);
			if(isCurious(r)) {
				product *= r;
			}
		}
	}

	std::cout << product.reduce().d() << std::endl;

	std::cout << isCurious(Rational(49, 98)) << std::endl;
	return 0;
}

bool isCurious(Rational r) {
	r = r.abs();
	unsigned a, b, x, y; // ab/xy
	a = r.n() / 10;
	b = r.n() % 10;
	x = r.d() / 10;
	y = r.d() % 10;

	if((a == b && x == y)) {
		return false;
	}

	bool curious = false;

	if(x) curious = curious || (r == Rational(b, x) && a == y);
	if(y) curious = curious || (r == Rational(a, y) && b == x);
	
	if(curious) r.print();

	return curious;
}
