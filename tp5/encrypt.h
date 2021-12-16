#ifndef ENCRYPT
#define ENCRYPT

#include <string>
#include <fstream>
#define FUN_FAILURE -1
#define FUN_SUCCESS 1

namespace encryption{
	class Encrypt{
	public:
		Encrypt();
		std::string plain() const;
		std::string cipher() const;
		virtual void encode(std::string const filename) = 0;
		virtual void decode(std::string const filename) = 0;
	protected:
		std::string _plain;
		std::string _cipher;
	};
	int read(std::string const filename, std::string& text);
	int write(std::string const filename, std::string& text);
}

#endif