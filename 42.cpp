#include <iostream>
#include <fstream>
#include <string>
#include "../mathlib/algorithm.h"

void extendList(unsigned);
bool isTriangular(unsigned);
unsigned wordVal(const std::string&);

std::vector<unsigned> tnums(1, 1);

int main() {
	extendList(50);

	std::ifstream fin("files/p042_words.txt");
	std::string input;

	if(fin.is_open()) {

		int count = 0;
		while(!fin.eof()) {
			std::getline(fin, input, '\"');
			std::getline(fin, input, '\"');

			if(isTriangular(wordVal(input)))
				++count;

			std::getline(fin, input, ',');
		}

		std::cout << count << std::endl;
	}
	else {
		throw std::runtime_error("Unable to open file.");
	}

	return 0;
}

void extendList(unsigned n) {
	while(tnums[tnums.size() - 1] < n)
		tnums.push_back(tnums.size() + 1 + tnums[tnums.size() - 1]);
}

bool isTriangular(unsigned n) {
	extendList(n);
	return Math::binary_search(tnums, n);
}

unsigned wordVal(const std::string &str) {
	unsigned val = 0;
	for(unsigned i = 0; i < str.size(); ++i)
		val += str[i] - 'A' + 1;
	return val;
}
