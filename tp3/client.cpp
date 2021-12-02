#include "client.h"

namespace person {
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
	void Client::display_cart() const{
		for(auto p in product : _cart)
			std::cout << p.title() << std::endl;
	}
	void Client::add_cart(Product p){
		auto it = find(_cart.begin(), _cart.end(), product);
		if(it == _cart.end()){
			_cart.add(p);
		}
		else {
			*it.update_quantity_choisi(1);
		}
	}
	void Client::clear_cart(){
		_cart.clear();
	}
	void Client::update_product_quantity(Product& product, int new_quantity){
		product.update_quantity_choisi(new_quantity);
	}
	void Client::delete_product(Product& product){
		auto it = find(_cart.begin(), _cart.end(), product);
		if(it != _cart.end()){
			_cart.erase(it);
		} else {
			std::cout << "Ce produit n'est pas dans ton panier" << std::endl;
		}
	}
	friend std::ostream& operator<< (std::ostream& os, Client& client);
}