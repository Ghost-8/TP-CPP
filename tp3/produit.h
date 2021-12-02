#ifndef PRODUCT
#define PRODUCT

#include <iostream>
#include <string>
#include <assert.h>

namespace magasin{
	class Product{
	public:
		Product(int id, std::string title, std::string description, 
			    int quantity, float price, int quantite_choisi);
		int id() const;
		std::string title() const;
		std::string description() const;
		int quantity() const;
		float price() const; 
		int quantite_choisi() const;
		void update_quatity(int q);
		void update_quatity_choisi(int q);
		friend std::ostream& operator<< (std::ostream& os, Product& product);
	private:
		int _id;
		std::string _title;
		std::string _description;
		int _quantity;
		float _price; 
		int _quantite_choisi;
	};
}

#endif