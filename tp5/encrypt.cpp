#include "encrypt.h"

namespace encryption{
	Encrypt::Encrypt() {}

	std::string Encrypt::plain() const{
		return _plain;
	}

	std::string Encrypt::cipher() const{
		return _cipher;
	}

	int read(std::string const filename, std::string& text){
		std::ifstream flux(filename.c_str());
		if(flux){
			std::string word;
			while(flux >> word){
				text += (word + " ");
			}
			flux.close();
		}
		else{
			return FUN_FAILURE;
		}
		return FUN_SUCCESS;
	}

	int write(std::string const filename, std::string& text){
		std::ofstream flux(filename.c_str());
		if(flux){
			flux << text << std::endl;
			flux.close();
		}
		else{
			return FUN_FAILURE;
		}
		return FUN_SUCCESS;
	}
}