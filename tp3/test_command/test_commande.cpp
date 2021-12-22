#include "produit.h"
#include "client.h"
#include "commande.h"


int main(int argc, char const *argv[]){
	std::cout << "Initialisation et affichage d'une commande" << std::endl;
	person::Client c1(1, "Hamady", "Coulibaly");
	magasin::Product p1(1, "PS4", "Jeu vidéo", 10, 299.98);
	magasin::Product p2(2, "PS5", "Jeu vidéo", 10, 399.98);
	magasin::Product p3(3, "Xbox", "Jeu vidéo", 10, 199.98);
	c1.add_cart(p1);
	c1.add_cart(p2);
	c1.add_cart(p3);
	int id = 1;
	magasin::Command cmd(id, c1, c1.cart(), magasin::Status::not_delivered);
	std::cout << cmd;
	std::cout << std::endl;

	std::cout << "Mise à jour du statut d'une commande" << std::endl;
	cmd.update_status(magasin::Status::delivered);
	std::cout << cmd;
}