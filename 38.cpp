#include <iostream>
#include "../mathlib/mathlib.h"

bool pandigital(unsigned);

int main() {
	unsigned largest = 0;
	unsigned *nums;
	unsigned num, place;

	for(unsigned i = 2; i < 10; ++i) {
		nums = new unsigned[i];

		for(unsigned j = 1;; ++j) {
			for(unsigned k = 0; k < i; ++k) {
				nums[k] = j * (k + 1);
			}

			num = 0;
			place = 1;
			for(int k = i - 1; k >= 0; --k) {
				num += place * nums[k];
				place *= Math::pow(10, Math::countdigits(nums[k]));
			}

			if(pandigital(num) && num > largest)
				largest = num;
			else if(num > 987654321)
				break;
		}

		delete[] nums;
	}

	std::cout << largest << std::endl;

	return 0;
}

bool pandigital(unsigned n) {
	bool digits[9];
	for(unsigned i = 0; i < 9; ++i)
		digits[i] = false;

	unsigned index;
	while(n) {
		index = n % 10;
		if(index)
			--index;
		else
			return false;

		if(digits[index])
			return false;
		
		digits[index] = true;
		n /= 10;
	}

	for(unsigned i = 0; i < 9; ++i) {
		if(!digits[i])
			return false;
	}

	return true;
}
