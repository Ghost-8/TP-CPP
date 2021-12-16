#include "enigma.h"

namespace encryption{
	Enigma::Enigma(): Encrypt() {}

	void transform_to_number(std::string& text, std::vector<int>& number){
		int size = text.length();
		number.assign(size, -128);
		for(size_t i=0; i<text.length(); ++i){
			if(text[i] >= 'a' && text[i] <= 'z'){
				number.at(i) = text[i] - ASCII_a;
			}
			else{
				number.at(i) = text[i];
			}
		}
	}

	void transform_to_string(std::vector<int>& number, std::string& text){
		for(size_t i=0; i<number.size(); ++i){
			if(number.at(i) >= A && number.at(i) <= Z){
				text += (char)(number[i] + ASCII_a);
			}
			else {
				text += (char)number.at(i);
			}
		}
	}

	void Enigma::encode(std::string const filename){
		std::vector<int> text;
		if(read(filename, _plain)){
			transform_to_number(_plain, text);
		}
		else{
			std::cout << "ERREUR, impossible de lire le fichier\n";
			return;
		}

		std::vector<int> result;
		size_t size = text.size();
		size_t i = 0;
		int i1 = 0;		// compteur ring1
		int i2 = 0;		// compteur ring2
		while(i<size){
			while(i1 < SIZE && i < size){
				if(text[i] >= A && text[i] <= Z){
					int pos1 = text[i];
					int pos2 = _ring[(pos1+i1)%SIZE];
					int letter = _ring2[(pos2+i2)%SIZE];
					result.push_back(letter);
					++i1;
				}
				else{
					result.push_back(text[i]);
				}
				++i;
			}
			++i2;
			i2 %= SIZE;
			i1 %= SIZE;
		}

		transform_to_string(result, _cipher);
		std::string newfile = "encrypted.txt";
		if(write(newfile, _cipher)){
			std::cout << "Chiffrement effectué avec succès !\n";
		}
		else{
			std::cout << "ERREUR, impossible d'écrire dans le fichier.\n";
			return;
		}
	}

	void Enigma::decode(std::string const filename){
		std::vector<int> text;
		if(read(filename, _cipher)){
			transform_to_number(_cipher, text);
		}
		else{
			std::cout << "ERREUR, impossible de lire le fichier.\n";
			return;
		}

		std::vector<int> result;

		size_t size = text.size();
		int i1 = 0; 
		int i2 = 0;
		size_t i = 0;
		while(i<size){
			while(i1 < SIZE && i < size){
				if(text[i] >= A && text[i] <= Z){
					auto it = std::find(_ring2.begin(), _ring2.end(), text[i]);
					int position = (std::distance(_ring2.begin(), it) - i2 + SIZE)%SIZE ;
					auto it2 = std::find(_ring.begin(), _ring.end(), position);
					int letter = std::distance(_ring.begin(), it2) - i1;
					letter = (letter+SIZE)%SIZE;
					result.push_back(letter);
					++i1;
				}
				else{
					result.push_back(text[i]);
				}
				++i;
			}
			++i2;
			i2 %= SIZE;
			i1 %= SIZE;
		}

		transform_to_string(result, _plain);
		std::string newfile = "decrypted.txt";
		if(write(newfile, _plain)){
			std::cout << "Déchiffrement effectué avec succès !\n";
		}
		else{
			std::cout << "ERREUR, impossible d'écrire dans le fichier.\n";
			return;
		}
	}
}
