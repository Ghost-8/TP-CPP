#ifndef CLIENT
#define CLIENT 	

#include <string>
#include <vector>
#include <ostream>
#include <algorithm>
#include "produit.h"


namespace person{
	class Client{
		public:
			Client(int id, std::string firstname, std::string lastname);
			int id() const;
			std::string firstname() const;
			std::string lastname() const;
			std::vector<magasin::Product> cart() const;
			void add_cart(magasin::Product& product);
			void clear_cart();
			void update_product_quantity(const magasin::Product& product, const int new_quantity);
			void delete_product(const magasin::Product& product);
		private:
			int _id;
			std::string _firstname;
			std::string _lastname;
			std::vector<magasin::Product> _cart;
	};
	std::ostream& operator<< (std::ostream& os, const Client& client);
	std::vector<person::Client>::iterator find(std::vector<person::Client>& container, const Client& client);
	std::vector<person::Client>::iterator find(std::vector<person::Client>& container, const int id_client);
}

#endif