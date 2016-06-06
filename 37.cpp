#include <iostream>
#include <list>
#include "../mathlib/prime.h"
#include "../mathlib/mathlib.h"

bool rightTruncatable(unsigned);

PrimeSieve p;

int main() {
	unsigned digits[] = {1, 2, 3, 5, 7, 9};
	std::list<unsigned> nums;
	nums.push_back(3);
	nums.push_back(7);
	unsigned sum = 0, count = 0;
	unsigned num, place;

	while(count < 11) {
		num = nums.front();
		nums.pop_front();
		
		if(p.isPrime(num)) {
			if(rightTruncatable(num) && num > 10) {
				std::cout << num << std::endl;
				sum += num;
				++count;
			}

			place = Math::pow(10, Math::countdigits(num));

			for(unsigned i = 0; i < sizeof(digits) / sizeof(unsigned); ++i) {
				unsigned temp = (place * digits[i]) + num;
				nums.push_back(temp);
			}
		}
	}

	std::cout << sum << std::endl;

	return 0;
}

bool rightTruncatable(unsigned n) {
	while(n) {
		if(!p.isPrime(n))
			return false;
		n /= 10;
	}
	return true;
}

