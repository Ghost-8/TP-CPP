#ifndef PRODUCT
#define PRODUCT

#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
#include <algorithm>

namespace magasin{
	class Product{
	public:
		Product(int id, std::string title, std::string description, int quantity, float price);
		int id() const;
		std::string title() const;
		std::string description() const;
		int quantity() const;
		float price() const; 
		int quantite_client() const;
		void update_quantity(int q);
		void update_quantity_client(int q);
	private:
		int _id;
		std::string _title;
		std::string _description;
		int _quantity;
		float _price; 
		int _quantite_client = 0;
	};
	std::vector<magasin::Product>::iterator find(std::vector<magasin::Product>& container, const magasin::Product& product);
	std::vector<magasin::Product>::iterator find(std::vector<magasin::Product>& container, const int id_product);
	std::ostream& operator<< (std::ostream& os, const Product& product);
}

#endif