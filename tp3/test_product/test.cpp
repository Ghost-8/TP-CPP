#include "produit.h"
	
int main(int argc, char const *argv[]){

	std::cout << "initialisation de l'objet" << std::endl;
	magasin::Product p1(1, "PS4", "Jeu vidéo", 1, 299.98);
	std::cout << p1;
	std::cout << std::endl;

	std::cout << "Mise à jour de la quantité disponible" << std::endl;
	p1.update_quantity(10);
	std::cout << "Nouvelle quantité = " << p1.quantity() << std::endl;
	std::cout << std::endl;

	//std::cout << "Test de l'assertion dans la fonction update_quantity()" << std::endl;
	//p1.update_quatity(-1);
	
	std::cout << "Test de la fonction update_quatity_client()" << std::endl;
	p1.update_quantity_client(2);
	std::cout << "Quantité dans le panier du client : " << p1.quantite_client() << std::endl;
	std::cout << "Quantité restant : " << p1.quantity() << std::endl;

	return 0;
}