#ifndef MAGASIN
#define MAGASIN

#include <string>
#include <vector>
#include <ostream>
#include <algorithm>
#include "produit.h"
#include "client.h"
#include "commande.h"
#define FUN_FAILURE 0
#define FUN_SUCCESS 1

namespace magasin {
	class Magasin {
	public:
		Magasin() = default;
		std::vector<Product> products() const;
		std::vector<person::Client> clients() const;
		std::vector<Command> commands() const;
		int new_product(const Product& product);
		int new_client(const person::Client& client);
		void display_product() const;
		void display_client() const;
		void display_command() const;
		void update_product_quantity(const Product& product, const int quantity);
		void update_command_status(const Command& command, const Status status);
		void find_client(const int id) const;
		void find_client(const std::string name) const;
		void display_client_command(const person::Client& client);
		void validate(magasin::Command& command, person::Client& client);
		void add_cart(person::Client& client, Product& product);
	private:
		std::vector<Product> _products;
		std::vector<person::Client> _clients;
		std::vector<Command> _commands;
		void new_command(const Command& command);
	};
}

#endif