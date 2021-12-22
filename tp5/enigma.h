#ifndef ENIGMA
#define ENIGMA

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include "encrypt.h"

#define SIZE 26
#define A 0
#define Z 25
#define ASCII_a 97

namespace encryption{
	class Enigma : public Encrypt{
	public:
		Enigma();
		void encode(std::string const filename) override;
		void decode(std::string const filename) override;
		
	private:
		std::array<int,SIZE> const _ring = {12, 18, 1, 8, 6, 25, 2, 5, 9, 0, 13, 16, 17, 3, 24, 4, 23, 7, 10, 14, 11, 15, 19, 21, 22, 20};
		std::array<int,SIZE> const _ring2 = {23, 18, 7, 4, 16, 11, 2, 22, 21, 0, 13, 5, 12, 3, 24, 8, 17, 1, 20, 14, 25, 6, 19, 9, 10, 15};
	};
	void transform_to_number(const std::string& text, std::vector<int>& number);
	void transform_to_string(const std::vector<int>& number, std::string& text);
}

#endif