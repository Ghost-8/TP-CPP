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
			std::vector<magasin::Product> cart();
			void add_cart(magasin::Product& p);
			void clear_cart();
			void update_product_quantity(magasin::Product& product, int new_quantity);
			void delete_product(magasin::Product& product);
			friend std::ostream& operator<< (std::ostream& os, const Client& client);
		private:
			int _id;
			std::string _firstname;
			std::string _lastname;
			std::vector<magasin::Product> _cart;
	};
}

#endif