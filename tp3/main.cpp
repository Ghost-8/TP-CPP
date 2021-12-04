#include <iostream>
#include "produit.h"
#include "client.h"
#include "commande.h"
#include "magasin.h"

int main(int argc, char const *argv[]){
	
	// Teste product
	
	/*
	std::cout << "initialisation de l'objet" << std::endl;
	magasin::Product p1(1, "PS4", "Jeu vidéo", 1, 299.98);
	std::cout << p1;
	std::cout << "Test des getters" << std::endl;
	std::cout << "id : " << p1.id() << std::endl << "titre : " << p1.title() << std::endl << "Description : " << p1.description() << std::endl << "Quantité : " << p1.quantity() << std::endl << "Prix : " << p1.price() << std::endl << "Quantité du client : " << p1.quantite_client() << std::endl;
	std::cout << "Mise à jour de la quantité disponible" << std::endl;
	p1.update_quantity(10);
	std::cout << "Quantité = " << p1.quantity() << std::endl;
	//std::cout << "Test de l'assertion dans la fonction update_quantity()" << std::endl;
	//p1.update_quatity(-1);
	std::cout << "Test de la fonction update_quatity_client()" << std::endl;
	p1.update_quantity_client(2);
	std::cout << "Quantité dans le panier du client : " << p1.quantite_client() << std::endl << "Quantité restant : " << p1.quantity() << std::endl;
	*/

	// Test client
	/*
	//std::cout << "initialisation de l'objet" << std::endl;
	person::Client c1(1, "Hamady", "Coulibaly");
	std::cout << c1;
	std::cout << "Test des getters" << std::endl;
	std::cout << "id : " << c1.id() << std::endl << "Prénom : " << c1.firstname() << std::endl << "Nom : " << c1.lastname() << std::endl;
	std::cout << "Test du panier" << std::endl;
	magasin::Product p1(1, "PS4", "Jeu vidéo", 10, 299.98);
	magasin::Product p2(2, "PS5", "Jeu vidéo", 10, 399.98);
	magasin::Product p3(3, "Xbox", "Jeu vidéo", 10, 199.98);
	c1.add_cart(p1);
	c1.add_cart(p2);
	c1.add_cart(p3);
	std::cout << c1;
	std::cout << "Test de update product quantity" << std::endl;
	c1.update_product_quantity(p3, 3);
	std::cout << c1;
	std::cout << "Test de delete_product" << std::endl;
	c1.delete_product(p2);
	std::cout << c1;
	std::cout << "Test de clear panier" << std::endl;
	c1.clear_cart();
	std::cout << c1;
	*/

	// Test commande
	/*
	person::Client c1(1, "Hamady", "Coulibaly");
	magasin::Product p1(1, "PS4", "Jeu vidéo", 10, 299.98);
	magasin::Product p2(2, "PS5", "Jeu vidéo", 10, 399.98);
	magasin::Product p3(3, "Xbox", "Jeu vidéo", 10, 199.98);
	c1.add_cart(p1);
	c1.add_cart(p2);
	c1.add_cart(p3);
	magasin::Command cmd(c1, c1.cart(), magasin::Status::not_delivered);
	std::cout << cmd;
	*/
	
	// Test magasin

	magasin::Magasin m1;
	person::Client c1(1, "Hamady", "Coulibaly");
	person::Client c2(2, "Alou", "Coulibaly");
	magasin::Product p1(1, "PS4", "Jeu vidéo", 10, 299.98);
	magasin::Product p2(2, "PS5", "Jeu vidéo", 10, 399.98);
	magasin::Product p3(3, "Xbox", "Jeu vidéo", 10, 199.98);
	magasin::Product p4(4, "PSnew", "Jeu vidéo", 0, 499.98);
	m1.new_client(c1);
	m1.new_client(c2);
	m1.new_product(p1);
	m1.new_product(p2);
	m1.new_product(p3);
	m1.new_product(p4);
	c1.add_cart(p1);
	c1.add_cart(p2);
	c1.add_cart(p3);
	c2.add_cart(p1);
	c2.add_cart(p3);
	magasin::Command cmd(c1, c1.cart(), magasin::Status::not_delivered);
	magasin::Command cmd2(c2, c2.cart(), magasin::Status::not_delivered);
	m1.validate(cmd, c1);
	m1.validate(cmd2, c2);
	c1.add_cart(p4);
	magasin::Command cmd3(c1, c1.cart(), magasin::Status::not_delivered);
	m1.validate(cmd3, c1);
	//m1.update_command_status(cmd, magasin::Status::delivered);
	//m1.display_product();
	//std::cout << std::endl;
	//m1.update_product_quantity(p1, 5);
	//m1.display_product();
	//m1.display_client();
	m1.display_command();
	//m1.find_client(1);
	//m1.find_client("Coulibaly");
	//m1.display_client_command(c1);

	return 0;
}
