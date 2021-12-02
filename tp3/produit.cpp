#include "produit.h"

namespace magasin{
	Product::Product(int id, std::string title, std::string description, int quantity, 
		float price, int quantite_choisi = 0) : _id(id), _title(title), _description(description), _quantity(quantity), _price(price) {}
	int Product::id() const{
			return _id;
	}
	std::string Product::title() const{
		return _title;
	}
	std::string Product::description() const{
		return _description;
	}
	int Product::quantity() const{
		return _quantity;
	}
	float Product::price() const{
		return _price;
	}
	void Product::update_quatity(int q){
		bool test = (q > 0);
		assert(test && "Donnez un entier > 0");
		_quantity += q;
	}
	int Product::quantite_choisi() const{
		return _quantite_choisi;
	}
	void Product::update_quatity_choisi(int q){
		bool test = (q > 0);
		assert(test && "Donnez un entier > 0");
		if(_quantite_choisi+q > _quantity){
			std::cout << "Il ne reste pas autant de produits";
		}
		else{
			_quantite_choisi += q;
			_quantity -= q;
		}
	}
	std::ostream& operator<< (std::ostream& os, Product& product){
		os << "id du produit : " << product._id << std::endl << "Nom du produit : " << product._title << std::endl << "Description : " << product._description << std::endl << "Quantité disponible : " << product._quantity << std::endl << "Prix : " << product._price << std::endl;
		return os;
	}
}