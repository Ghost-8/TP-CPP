#include "magasin.h"

namespace magasin{
	void Magasin::new_product(Product& product){
		_products.push_back(product);
	}

	void Magasin::new_client(person::Client& client){
		_clients.push_back(client);
	}

	void Magasin::new_command(Command& command){
		_commands.push_back(command);
	}

	void Magasin::display_product() const{
		for(auto p: _products){
			std::cout << p;
		}
	}

	void Magasin::display_client() const{
		for(auto c : _clients){
			std::cout << c;
		}
	}

	void Magasin::display_command() const{
		for(auto cmd : _commands){
			std::cout << cmd << std::endl;
		}
	}

	void Magasin::update_product_quantity(const Product& product, int quantity){
		auto it = magasin::find(_products, product);
		if(it != _products.end()){
			(*it).update_quantity(quantity);
		}
		else {
			std::cout << "Ce produit n'est pas enregistré dans le magasin !!!";
		}
	}

	void Magasin::update_command_status(const Command& command, const Status status){
			auto it = find_if(_commands.begin(), _commands.end(), [command](Command obj){ return obj.id_client() == command.id_client(); } );
			if(it != _commands.end()){
				(*it).update_status(status);
			} 
			else{
				std::cout << "Cette commande n'existe pas !!!" << std::endl;
			}
	}

	void Magasin::find_client(int id) const{
		auto it = _clients.begin();
		while (it != _clients.end()) { 
			it = std::find_if(it, _clients.end(), [id](const person::Client& obj){return id == obj.id(); });;
			if (it != _clients.end()) { 
            	auto index = std::distance(_clients.begin(), it); 
            	std::cout << _clients.at(index);
            	++it;
			}
		}
	}

	void Magasin::find_client(std::string name) const{
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
			it = std::find_if(it, _commands.end(), [client](const magasin::Command& obj){ return client.id() == obj.id_client(); });
			if (it != _commands.end()) { 
            	auto index = std::distance(_commands.begin(), it); 
            	std::cout << _commands.at(index);
            	++it;
			}
		}

	}

	void Magasin::validate(magasin::Command& command, person::Client& client){
		bool test = true;
		for(auto i : client.cart()){
			if(i.quantity() <= 0){
				test = false;
			}
		}
		if(test){
			(*this).new_command(command);	
		}
		else{
			std::cout << "Certains produits de votre panier ne sont plus disponibles" << std::endl;
		}
		client.clear_cart();
	}
}