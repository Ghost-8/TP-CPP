#include "client.h"
#include "produit.h"

int main(int argc, char const *argv[]){
	std::cout << "initialisation de l'objet" << std::endl;
	person::Client c1(1, "Hamady", "Coulibaly");
	std::cout << c1;
	std::cout << "Test du panier, ajout de 3 produits" << std::endl;
	magasin::Product p1(1, "PS4", "Jeu vidéo", 10, 299.98);
	magasin::Product p2(2, "PS5", "Jeu vidéo", 10, 399.98);
	magasin::Product p3(3, "Xbox", "Jeu vidéo", 10, 199.98);
	c1.add_cart(p1);
	c1.add_cart(p2);
	c1.add_cart(p3);
	std::cout << c1;
	std::cout << "Test de update_product_quantity" << std::endl;
	c1.update_product_quantity(p1, 5);
	c1.update_product_quantity(p2, 6);
	c1.update_product_quantity(p3, 3);
	std::cout << c1;
	std::cout << "Test de delete_product" << std::endl;
	c1.delete_product(p2);
	std::cout << c1;
	std::cout << "Test de clear panier" << std::endl;
	c1.clear_cart();
	std::cout << c1;
}
