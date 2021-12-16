#include <iostream>
#include "encrypt.h"
#include "enigma.h"

int main(int argc, char const *argv[]){
	
	encryption::Enigma enigma1;
	encryption::Enigma enigma2;
	std::string filename = "file_to_encrypt.txt";
	std::string filename2 = "encrypted.txt";

	std::cout << "\t*** Enigma 1 ***" << std::endl;
	enigma1.encode(filename);
	std::cout << enigma1.cipher();
	std::cout << std::endl << std::endl;

	std::cout << "\t*** Enigma 2 ***" << std::endl;
	enigma2.decode(filename2);
	std::cout << enigma2.plain();
	std::cout << std::endl;

	return 0;
}