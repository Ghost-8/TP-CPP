#include "client.h"

namespace person{
	Client::Client(int id, std::string firstname, std::string lastname) : _id(id), _firstname(firstname), _lastname(lastname){}

	int Client::id() const{
		return _id;
	}

	std::string Client::firstname() const{
		return _firstname;
	}

	std::string Client::lastname() const{
		return _lastname;
	}

	std::vector<magasin::Product> Client::cart() const{
		return _cart;		
	}

	void Client::add_cart(magasin::Product& product){
		auto it = magasin::find_product(_cart, product);
		if(it == _cart.end()){
			product.update_quantity_client(1);
			_cart.push_back(product);
		}
		else {
			// Ajoute 1 à la quantité du produit s'il est déjà dans le panier
			(*it).update_quantity_client( ((*it).quantite_client()) + 1 );
		}
	}

	void Client::clear_cart(){
		_cart.clear();
	}

	void Client::update_product_quantity(const magasin::Product& product, const int new_quantity){
		auto it = magasin::find_product(_cart, product);
		if(it != _cart.end()){
			std::cout << "Ce produit n'est pas dans le panier !!!\n";
		}
		else {
			(*it).update_quantity_client(new_quantity);
		}
	}

	void Client::delete_product(const magasin::Product& product){
		auto it = magasin::find_product(_cart, product);
		if(it != _cart.end()){
			_cart.erase(it);
		} else {
			std::cout << "Ce produit n'est pas dans le panier.\n" << std::endl;
		}
	}

	std::ostream& operator<< (std::ostream& os, const Client& client){
		os << client.firstname() << " " << client.lastname() << std::endl;
		for(auto p : client.cart())
			os << p.title() << " : " << p.quantite_client() << std::endl;
		return os;
	}
	std::vector<person::Client>::iterator find(std::vector<person::Client>& container, const Client& client){
		auto it = std::find_if(container.begin(), container.end(), [client](const Client& obj){ return obj.id() == client.id(); });
		return it;
	}
	std::vector<person::Client>::iterator find(std::vector<person::Client>& container, const int id_client){
		auto it = std::find_if(container.begin(), container.end(), [id_client](const Client& obj){ return obj.id() == id_client; });
		return it;
	}
}