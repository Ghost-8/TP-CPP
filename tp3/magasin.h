#ifndef MAGASIN
#define MAGASIN

#include <string>
#include <vector>
#include <ostream>
#include <algorithm>
#include "produit.h"
#include "client.h"
#include "commande.h"

namespace magasin {
	class Magasin {
	public:
		Magasin() = default;
		void display_product() const;
		void display_client() const;
		void display_command() const;
		void new_product(Product& product);
		void new_client(person::Client& client);
		void new_command(Command& command);
		void update_product_quantity(const Product& product, int quantity);
		void update_command_status(const Command& command, const Status status);
		void find_client(int id) const;
		void find_client(std::string name) const;
		void display_client_command(const person::Client& client);
		void validate(magasin::Command& command, person::Client& client);
	private:
		std::vector<Product> _products;
		std::vector<person::Client> _clients;
		std::vector<Command> _commands;
	};

}

#endif