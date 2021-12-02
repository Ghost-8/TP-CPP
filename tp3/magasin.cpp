#include "magasin.h"

namespace magasin{
	Magasin::Magasin(std::vector<Product> products, std::vector<Client> clients, 
			    std::vector<Command> commands): _products(produits), _clients(clients),
			    _commands(commands){};
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
}