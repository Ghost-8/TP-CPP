#include "magasin.h"

namespace magasin{
	Magasin::Magasin(){}

	std::vector<Product> Magasin::products() const{
		return _products;
	}

	std::vector<person::Client> Magasin::clients() const{
		return _clients;
	}

	std::vector<Command> Magasin::commands() const{
		return _commands;
	}

	int Magasin::new_product(const Product& product){
		auto it = magasin::find_product(_products, product.id());
		if(it != _products.end()){
			std::cout << "Ce produit existe déjà, opération abandonnée !!!\n";
			return FUN_FAILURE;
		}
		else{
			_products.push_back(product);
			return FUN_SUCCESS;
		}
	}

	int Magasin::new_client(const person::Client& client){
		auto it = person::find(_clients, client.id());
		if(it != _clients.end()){
			std::cout << "Ce client existe déjà, opération abandonnée !!!\n";
			return FUN_FAILURE;
		}
		else{
			_clients.push_back(client);
			return FUN_SUCCESS;
		}
	}

	int Magasin::new_command(const Command& command){
		auto it = magasin::find_command(_commands, command.id());
		if(it != _commands.end()){
			std::cout << "Cette commande existe déjà, opération abandonnée !!!\n";
			return FUN_FAILURE;
		}
		else{
			_commands.push_back(command);
			return FUN_SUCCESS;
		}
	}

	void Magasin::display_product() const{
		std::cout << "Liste des produits : " << std::endl;
		for(auto p: _products){
			std::cout << p;
		}
	}

	void Magasin::display_client() const{
		std::cout << "Liste des clients : " << std::endl;
		for(auto c : _clients){
			std::cout << c;
			std::cout << std::endl;
		}
	}

	void Magasin::display_command() const{
		std::cout << "Liste des commandes : " << std::endl;
		for(auto cmd : _commands){
			std::cout << cmd << std::endl;
		}
	}

	void Magasin::update_product_quantity(const Product& product, const int quantity){
		if(quantity < 0){
			std::cout << "Donnez une quantité > 0." << std::endl;
			return;
		}
		auto it = magasin::find_product(_products, product.id());
		if(it == _products.end()){
			std::cout << "\nCe produit n'est pas enregistré dans le magasin !!!\n";
		}
		else {
			(*it).update_quantity(quantity);
		}
	}

	void Magasin::update_command_status(const Command& command, const Status status){
			auto it = find_command(_commands, command.id());
			if(it == _commands.end()){
				std::cout << "Cette commande n'est pas enregistrée dans le magasin !!!" << std::endl;
			} 
			else{
				(*it).update_status(status);
			}
	}

	void Magasin::find_client(const int id) const{
		auto it = _clients.begin();
		while (it != _clients.end()) { 
			it = std::find_if(it, _clients.end(), [id](const person::Client& obj){return id == obj.id(); });
			if (it != _clients.end()) { 
            	auto index = std::distance(_clients.begin(), it); 
            	std::cout << _clients.at(index);
            	++it;
			}
		}
	}

	void Magasin::find_client(const std::string name) const{
		auto it = _clients.begin();
		while (it != _clients.end()) { 
			it = std::find_if(it, _clients.end(), [name](const person::Client& obj){return ( name == obj.firstname() || ( name == obj.lastname() ) ); });
			if (it != _clients.end()) { 
            	auto index = std::distance(_clients.begin(), it); 
            	std::cout << _clients.at(index);
            	++it;
			}
		}
	}

	void Magasin::display_client_command(const person::Client& client){
		auto it = _commands.begin();
		while (it != _commands.end()) { 
			it = std::find_if(it, _commands.end(), [client](const magasin::Command& obj){ return client.id() == obj.client().id(); });
			if (it != _commands.end()) { 
            	auto index = std::distance(_commands.begin(), it); 
            	std::cout << _commands.at(index);
            	++it;
			}
		}
	}

	void Magasin::validate(magasin::Command& command, person::Client& client){
		bool test = true;
		auto it = person::find(_clients, client.id());
		auto list = (*it).cart();
		for(auto i : list){
			if(i.quantity() <= 0){
				test = false;
			}
		}
		if(!test){
			std::cout << "Certains produits de votre panier ne sont plus disponibles." << std::endl;
		}
		else{
			(*this).new_command(command);
		}
		(*it).clear_cart();
	}

	void Magasin::add_cart(const person::Client& client, Product& product){
		auto it = person::find(_clients, client);
		auto it2 = magasin::find_product(_products, product);
		(*it).add_cart(product);
		(*it2).update_quantity( (*it2).quantity() - 1 );
	}

	void Magasin::update_client_quantity(const person::Client& client, const magasin::Product& product, const int q){
		auto it = person::find(_clients, client);
		(*it).update_product_quantity(product, q);
	}

	void Magasin::delete_client_product(const person::Client& client, const magasin::Product& product){
		auto it = person::find(_clients, client);
		(*it).delete_product(product);
	}

	Command Magasin::make_command(const int id, const person::Client& client, const Status status){
		auto it = person::find(_clients, client);
		magasin::Command cmd(id, (*it), magasin::Status::not_delivered);
		return cmd;
	}
}