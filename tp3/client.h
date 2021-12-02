#ifndef CLIENT
#define CLIENT 	

#include <string>
#include <vector>
#include <ostream>


namespace person {
	struct QuantityProduct{
		int quantity;
		std::string name;
	}
	class Client{
		public:
			Client(int id, std::string firstname, std::string lastname);
			int id() const;
			std::string firstname() const;
			std::string lastname() const;
			void display_cart() const;
			void add_cart(Product const p);
			void clear_cart();
			void update_product_quantity(Product& product, int new_quantity);
			void delete_product(std::string p_title);
			friend std::ostream& operator<< (std::ostream& os, Client& client);
		private:
			int _id;
			std::string _firstname;
			std::string _lastname;
			std::vector<Product> _cart;
	};
}

#endif