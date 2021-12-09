#include "main.h"

int main(int argc, char const *argv[]){
	magasin::Magasin m;

	std::cout << "*Ajout de deux clients*" << std::endl;
	person::Client c1(1, "Hamady", "Coulibaly");
	person::Client c2(2, "Alou", "Coulibaly");	
	m.new_client(c1);
	m.new_client(c2);
	m.display_client();
	std::cout << std::endl;

	std::cout << "*Ajout de 4 produits*" << std::endl;
	magasin::Product p1(1, "PS4", "Jeu vidéo", 10, 299.98);
	magasin::Product p2(2, "PS5", "Jeu vidéo", 10, 399.98);
	magasin::Product p3(3, "Xbox", "Jeu vidéo", 10, 199.98);
	magasin::Product p4(4, "PSnew", "Jeu vidéo", 0, 499.98);
	m.new_product(p1);
	m.new_product(p2);
	m.new_product(p3);
	m.new_product(p4);
	m.display_product();
	std::cout << std::endl;

	std::cout << "*Valider 3 commandes*" << std::endl;
	std::cout << "*Liste des commandes avant validation*" << std::endl;
	m.display_command();
	m.add_cart(c1, p1);
	m.add_cart(c1, p2);
	m.add_cart(c1, p3);
	m.add_cart(c2, p1);
	m.add_cart(c2, p3);
	magasin::Command cmd(c1, c1.cart(), magasin::Status::not_delivered);
	magasin::Command cmd2(c2, c2.cart(), magasin::Status::not_delivered);
	m.validate(cmd, c1);
	m.validate(cmd2, c2);
	m.add_cart(c1, p1);
	m.add_cart(c1, p2);
	m.add_cart(c1, p3);
	magasin::Command cmd3(c1, c1.cart(), magasin::Status::not_delivered);
	m.validate(cmd3, c1);
	std::cout << "*Liste des commandes après validation*" << std::endl;
	m.display_command();

	std::cout << "*Ajout d'un produit indisponible*" << std::endl;
	m.add_cart(c1, p3);
	m.add_cart(c1, p4);
	std::cout << std::endl;

	std::cout << "*Valider une commande dont un produit indisponible*" << std::endl;
	magasin::Command cmd4(c1, c1.cart(), magasin::Status::not_delivered);
	m.validate(cmd4, c1);
	std::cout << std::endl;

	std::cout << "*Mise à jour du statut de 2 commandes*" << std::endl;
	m.update_command_status(cmd, magasin::Status::delivered);
	m.update_command_status(cmd2, magasin::Status::delivered);
	m.display_command();

	std::cout << "*Mise à jour de la quantité de 2 produits*" << std::endl;
	std::cout << "*Avant la mise à jour*" << std::endl;
	m.display_product();
	std::cout << std::endl;
	m.update_product_quantity(p1, 5);
	m.update_product_quantity(p4, 30);
	std::cout << std::endl;
	std::cout << "*Après la mise à jour*" << std::endl;
	m.display_product();
	std::cout << std::endl;

	std::cout << "*Trouver un client selon son identifiant*" << std::endl;
	m.find_client(1);
	std::cout << std::endl;
	std::cout << "*Trouver un client selon son nom ou prénom*" << std::endl;
	m.find_client("Coulibaly");
	std::cout << std::endl;

	std::cout << "*Afficher les commandes d'un client*" << std::endl;
	m.display_client_command(c1);
}