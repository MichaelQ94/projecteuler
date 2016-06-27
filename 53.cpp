#include <iostream>
#include <vector>
#include "../mathlib/mathlib.h"

enum {
	MIN = 1,
	MAX = 100,
	THRESHOLD = 1000000
};

int main() {
	unsigned count = 0;
	for(unsigned n = MIN; n <= MAX; ++n) {
		for(unsigned r = 1; r <= n/2; ++r) {
			if(Math::choose(n, r) > THRESHOLD) {
				count += n + 1 - (2 * r);
				break;
			}
		}
	}

	std::cout << count << std::endl;

	return 0;
}
