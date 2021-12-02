#ifndef MAGASIN
#define MAGASIN

#include <string>
#include <vector>
#include <ostream>
#include "produit.h"
#include "client.h"
#include "commande.h"

namespace magasin {
	class Magasin {
	public:
		Magasin(std::vector<Product> products, std::vector<Client> clients, std::vector<Command> commands);
		void new_product(Product& product);
		void new_client(person::Client client);
		void new_command(Command& command);
		void display_product() const;
		void display_client() const;
		void display_command() const;
		void update_product_quantity();
		std::string find_client(int id) const;
		std::string find_client(std::string name) const;
		void validate();
	private:
		std::vector<Product> _products;
		std::vector<person::Client> _clients;
		std::vector<Command> _commands;
	};
}

#endif