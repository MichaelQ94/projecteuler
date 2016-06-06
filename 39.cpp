#include <iostream>

bool pythagoreanTriple(int, int, int);

int main() {
	int max = 0, maxp, solutions;

	for(int p = 12; p <= 1000; ++p) {
		solutions = 0;

		for(int i = 1; i < p / 3; ++i) {
			for(int j = i; j < (p - i - j); ++j) {
				if(pythagoreanTriple(i, j, p - i - j))
					++solutions;
			}
		}

		if(solutions > max) {
			max = solutions;
			maxp = p;
		}
	}

	std::cout << maxp << std::endl;

	return 0;
}

bool pythagoreanTriple(int a, int b, int c) {
	return c*c == a*a + b*b;
}
