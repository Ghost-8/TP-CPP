#include "produit.h"

namespace magasin{
	Product::Product(int id, std::string title, std::string description, int quantity, 
		float price) : _id(id), _title(title), _description(description), _quantity(quantity), _price(price) {
		bool test = (quantity >= 0 && price >= 0);
		assert(test && "Veuillez respecter le bon format des données");
	}
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
	void Product::update_quantity(int q){
		bool test = (q > 0);
		assert(test && "Donnez un entier > 0");
		_quantity = q;
	}
	int Product::quantite_client() const{
		return _quantite_client;
	}
	void Product::update_quantity_client(int q){
		bool test = (q > 0);
		assert(test && "Donnez un entier > 0");
		if(_quantite_client+q > _quantity){
			std::cout << "Il ne reste pas autant de produits" << std::endl;
		}
		else{
			_quantite_client = q;
		}
	}
	std::ostream& operator<< (std::ostream& os, const Product& product){
		os << "id du produit : " << product.id() << std::endl;
		os << "Nom du produit : " << product.title() << std::endl;
		os << "Description : " << product.description() << std::endl;
		os << "Quantité disponible : " << product.quantity() << std::endl;
		os << "Prix : " << product.price() << std::endl;
		return os;
	}
}