#include "produit.h"

namespace magasin{
	Product::Product(int id, std::string title, std::string description, int quantity, float price) : _id(id), _title(title), _description(description), _quantity(quantity), _price(price) {
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

	int Product::quantite_client() const{
		return _quantite_client;
	}

	void Product::update_quantity(const int q){
		if(q < 0){
			std::cout << "La quantité doit être supérieure ou égale à 0\n";
			return;
		}
		else{
			_quantity = q;
		}
	}

	void Product::update_quantity_client(const int q){
		bool test = (q > 0);
		assert(test && "Donnez un entier > 0");
		if(_quantite_client+q > _quantity){
			std::cout << "Stock insuffisant." << std::endl;
		}
		else{
			_quantite_client = q;
			_quantity -= q;
		}
	}

	void Product::set_id(const int id){
		_id = id;
	}

	std::ostream& operator<< (std::ostream& os, const Product& product){
		os << "id : " << product.id() << ", Nom : " << product.title() << ", Description : " << product.description() << ", Quantité disponible : " << product.quantity() << ", Prix : " << product.price() << std::endl;
		return os;
	}

	std::vector<magasin::Product>::iterator find_product(std::vector<magasin::Product>& container, const magasin::Product& product){
		auto it = std::find_if(container.begin(), container.end(), [product](const magasin::Product& obj){ return product.id() == obj.id(); });
		return it;
	}
	std::vector<magasin::Product>::iterator find_product(std::vector<magasin::Product>& container, const int id_product){
		auto it = std::find_if(container.begin(), container.end(), [id_product](const magasin::Product& obj){ return id_product == obj.id(); });
		return it;
	}
}