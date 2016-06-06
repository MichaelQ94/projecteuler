#include <iostream>
#include <vector>
#include "../mathlib/mathlib.h"

bool binarypalindrome(unsigned);
bool decimalpalindrome(unsigned);
std::vector<unsigned> binarypalindromes(unsigned);

int main() {
	unsigned sum = 0;
	for(int i = 0; i < 1000000; ++i) {
		if(binarypalindrome(i) && decimalpalindrome(i)) {
			std::cout << i << std::endl;
			sum += i;
		}
	}
	std::cout << sum << std::endl;
	
	std::vector<unsigned> palindromes;
	sum = 0;
	unsigned i = 0;
	while(true) {
		palindromes = binarypalindromes(i);
		for(unsigned j = 0; j < palindromes.size(); ++j) {
			if(palindromes[j] >= 1000000) {
				std::cout << sum << std::endl;
				return 0;
			}
			else if(decimalpalindrome(palindromes[j])) {
				std::cout << palindromes[j] << std::endl;
				sum += (palindromes[j]);
			}	
		}
		++i;
	}

	/*std::vector<unsigned> palindromes = binarypalindromes(6);
	for(unsigned i = 0; i < palindromes.size(); ++i) {
		std::cout << palindromes[i] << std::endl;
	}*/
	/*for(int j = 0; j < 7; ++j) {
		palindromes = binarypalindromes(j);
		for(unsigned i = 0; i < palindromes.size(); ++i) {
			std::cout << palindromes[i] << std::endl;
		}
	}*/

	return 0;
}

bool binarypalindrome(unsigned n) {
	unsigned shift = Math::countbits(n) - 1;
	for(unsigned i = 0; i < shift; ++i, --shift) {
		if(((n >> i) & 1) != ((n >> shift) & 1)) {
			return false;
		}
	}

	return true;
}

bool decimalpalindrome(unsigned n) {
	unsigned top = Math::countdigits(n);
	unsigned bot = 1;
	unsigned topn, botn;
	do {
		topn = (n / Math::pow(10, top - 1)) % 10;
		botn = (n / Math::pow(10, bot - 1)) % 10;
		
		if(topn != botn) return false;

		--top;
		++bot;
	} while(top > bot);

	return true;
}

std::vector<unsigned> binarypalindromes(unsigned length) {
	std::vector<unsigned> palindromes;
	
	if(length == 0)
		return palindromes;
	else if(length == 1) {
		palindromes.push_back(0);
		palindromes.push_back(1);
		return palindromes;
	}

	unsigned base = (1 << (length - 1)) | 1; // 1 ... 1
	unsigned shift = length / 2;
	unsigned max = 1 << (shift - !(length % 2));
	unsigned palindrome, reflect, rshift;
	for(unsigned i = 0; i < max; ++i) {
		palindrome = base; // 10 ... 01
		palindrome = palindrome | (i << shift); //1z ... xy00 .. 01
		rshift = !(length % 2);
		for(unsigned j = shift; j < length; ++j) {
			reflect = palindrome & (1 << j);
			palindrome = palindrome | (reflect >> rshift); // 1z ... xyy0 ... 01
			rshift += 2;
		} // 1z ... xyyx ... z1

		palindromes.push_back(palindrome);
	}
	return palindromes;
}
