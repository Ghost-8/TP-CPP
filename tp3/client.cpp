#include "client.h"

namespace person{
	Client::Client(int id, std::string firstname, std::string lastname) : _id(id), _firstname(firstname), _lastname(lastname){
	}
	int Client::id() const{
		return _id;
	}
	std::string Client::firstname() const{
		return _firstname;
	}
	std::string Client::lastname() const{
		return _lastname;
	}
	std::vector<magasin::Product> Client::cart(){
		return _cart;		
	}
	void Client::add_cart(magasin::Product& p){
		auto it = std::find_if(_cart.begin(), _cart.end(), [p](const magasin::Product& obj){return p.id() == obj.id(); });
		if(it == _cart.end()){
			p.update_quantity_client(1);
			_cart.push_back(p);
		}
		else {
			// Ajoute 1 à la quantité du produit s'il est déjà dans le panier
			(*it).update_quantity_client( ((*it).quantite_client()) + 1 );
		}
	}
	void Client::clear_cart(){
		_cart.clear();
	}
	void Client::update_product_quantity(magasin::Product& product, int new_quantity){
		auto it = std::find_if(_cart.begin(), _cart.end(), [product](const magasin::Product& obj){return product.id() == obj.id(); });
		if(it != _cart.end()){
			(*it).update_quantity_client(new_quantity);
		}
		else {
			std::cout << "Ce produit n'est pas dans le panier !!!";
		}
	}
	void Client::delete_product(magasin::Product& p){
		auto it = std::find_if(_cart.begin(), _cart.end(), [p](const magasin::Product& obj){return p.id() == obj.id(); });
		if(it != _cart.end()){
			_cart.erase(it);
		} else {
			std::cout << "Ce produit n'est pas dans le panier" << std::endl;
		}
	}
	std::ostream& operator<< (std::ostream& os, const Client& client){
		os << client.firstname() << " " << client.lastname() << std::endl;
		for(auto p : client._cart)
			os << p.title() << " : " << p.quantite_client() << std::endl;
		return os;
	}
}