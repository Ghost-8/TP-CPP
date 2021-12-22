#include "main.h"

int main(int argc, char const *argv[]){
	magasin::Magasin store;

	person::Client c1(1, "Hamady", "Coulibaly");
	person::Client c2(2, "Alou", "Coulibaly");
	person::Client c3(3, "Dior", "Tamdjo");
	person::Client c4(4, "Ibrahim", "Sissoko");
	person::Client c5(5, "Muhammed", "Cevik");

	store.new_client(c1);
	store.new_client(c2);
	store.new_client(c3);
	store.new_client(c4);
	store.new_client(c5);

	magasin::Product p1(1, "PS4", "Jeu vidéo", 10, 299.98);
	magasin::Product p2(2, "Arduino", "Microcontroleur", 50, 25);
	magasin::Product p3(3, "Raspberry Pi", "nano ordinateur", 30, 54.50);
	magasin::Product p4(4, "Arduino nano", "Microcontroleur", 17, 7.80);
	magasin::Product p5(5, "R. pico", "Microcontroleur", 15, 3.90);
	magasin::Product p6(6, "PS5", "Jeu vidéo", 5, 399.98);
	magasin::Product p7(7, "Xbox", "Jeu vidéo", 20, 349.99);
	magasin::Product p8(8, "Oled Magique", "TV", 25, 549.99);
	magasin::Product p9(9, "Wii", "Jeu vidéo", 10, 249.99);
	magasin::Product p10(10, "Yiri", "Matériel de jardinnage", 80, 19.99);

	store.new_product(p1);
	store.new_product(p2);
	store.new_product(p3);
	store.new_product(p4);
	store.new_product(p5);
	store.new_product(p6);
	store.new_product(p7);
	store.new_product(p8);
	store.new_product(p9);
	store.new_product(p10);

	store.add_cart(c1, p2);
	store.add_cart(c1, p3);
	store.add_cart(c1, p4);
	store.add_cart(c1, p5);

	store.add_cart(c2, p1);
	store.add_cart(c2, p6);
	store.add_cart(c2, p7);
	store.add_cart(c2, p8);
	store.add_cart(c2, p9);

	store.add_cart(c5, p10);

	int id_cmd = 0;

	magasin::Command cmd1(++id_cmd, c1, c1.cart(), magasin::Status::not_delivered);
	magasin::Command cmd2(++id_cmd, c2, c2.cart(), magasin::Status::not_delivered);
	magasin::Command cmd3(++id_cmd, c5, c5.cart(), magasin::Status::not_delivered);

	store.validate(cmd1, c1);
	store.validate(cmd2, c2);
	store.validate(cmd3, c5);

	char menu, sous_menu;

	std::cout << "Bienvenue !" << std::endl << std::endl;
	do{
		std::cout << "Menu : " << std::endl;
		std::cout << "Choisissez une action en entrant le chiffre correspondant : " << std::endl;
		std::cout << "1 : Gestion du magasin" << std::endl;
		std::cout << "2 : Gestion des utilisateurs" << std::endl;
		std::cout << "3 : Gestion des commandes" << std::endl;
		std::cout << "* : Une autre touche pour quitter !" << std::endl << std::endl;
		
		std::cin >> menu;
		if(menu == '1'){
			do{
				std::cout << std::endl;
				std::cout << "Vous êtes dans la section *Gestion du magasin*" << std::endl;
				std::cout << "Choisissez une action en entrant le chiffre correspondant : " << std::endl;
				std::cout << "1 : Ajout d'un produit" << std::endl;
				std::cout << "2 : Affichage des produits" << std::endl;
				std::cout << "3 : Mise à jour des quantités" << std::endl;
				std::cout << "4 : Pour revenir en arrière" << std::endl;
				std::cout << "* : Une autre touche pour quitter !" << std::endl << std::endl;
				std::cin >> sous_menu;
				if(sous_menu == '1'){					
					std::cout << "id : ";
					int id;
					if(!(std::cin >> id)){
						std::cout << "Mauvaise manipulation, exit !!!\n";
						return EXIT_FAILURE;
					}					
					std::cout << "titre : ";
					std::string title;
					std::cin.ignore();
					std::getline(std::cin, title);
					std::cout << "Description : ";
					std::string description;
					std::getline(std::cin, description);
					std::cout << "Quantité : ";
					int quantity;
					if(!(std::cin >> quantity)){
						std::cout << "Mauvaise manipulation, exit !!!\n";
						return EXIT_FAILURE;
					}				
					std::cout << "Prix : ";
					float price;
					if(!(std::cin >> price)){
						std::cout << "Mauvaise manipulation, exit !!!\n";
						return EXIT_FAILURE;
					}
					std::cout << std::endl;
					magasin::Product p(id, title, description, quantity, price);
					if(store.new_product(p)){
						std::cout << "Opération effectuée avec succès !!!\n";
					}
				}
				else if(sous_menu == '2'){
					store.display_product();
				}
				else if(sous_menu == '3'){
					std::cout << "id du produit : ";
					int id;
					if(!(std::cin >> id)){
						std::cout << "Mauvaise manipulation, exit !!!\n";
						return EXIT_FAILURE;
					}	
					std::cout << "nouvelle quantité : ";
					int new_quantity;
					if(!(std::cin >> new_quantity)){
						std::cout << "Mauvaise manipulation, exit !!!\n";
						return EXIT_FAILURE;
					}	
					auto list = store.products();
					auto it = magasin::find(list, id);
					store.update_product_quantity(*it, new_quantity);				
				}
				else if(sous_menu == '4'){}
				else {
					menu = FAILURE;
				}

			} while(sous_menu > '0' && sous_menu < '4');
		}
		else if(menu == '2'){
			do{
				std::cout << std::endl;
				std::cout << "Vous êtes dans la section *Gestion des utilisateurs*" << std::endl;
				std::cout << "Choisissez une action en entrant le chiffre correspondant : " << std::endl;
				std::cout << "1 : Ajout d'un client" << std::endl;
				std::cout << "2 : Affichage des clients" << std::endl;
				std::cout << "3 : Chercher un client" << std::endl;
				std::cout << "4 : Pour revenir en arrière" << std::endl;
				std::cout << "* : Une autre touche pour quitter !" << std::endl << std::endl;

				std::cin >> sous_menu;
				if(sous_menu == '1'){
					std::cout << "id : ";
					int id;
					if(!(std::cin >> id)){
						std::cout << "Mauvaise manipulation, exit !!!\n";
						return EXIT_FAILURE;
					}
					std::cout << "Prénom : ";
					std::string prenom;
					std::cin.ignore();
					std::getline(std::cin, prenom);
					std::cout << "Nom : ";
					std::string nom;
					std::getline(std::cin, nom);
					person::Client client(id, prenom, nom);
					if(store.new_client(client)){
						std::cout << "\nOpération effectuée avec succès !!!\n\n";
					}
				}
				else if(sous_menu == '2'){
					store.display_client();
					std::cout << std::endl;
				}
				else if(sous_menu == '3'){
					std::cout << "Tapez 0 pour une recherche par id et 1 pour une recherche par nom ou prénom :" << std::endl;
					char search;
					std::cin >> search;
					if(search == '0'){
						std::cout << "Veuillez saisir l'id du client : ";
						int id;
						if(!(std::cin >> id)){
							std::cout << "Mauvaise manipulation, exit !!!\n";
							return EXIT_FAILURE;
						}
						store.find_client(id);
					}
					else if(search == '1'){
						std::cout << "Veuillez saisir le nom ou le prénom du client : ";
						std::string name;
						std::cin.ignore();
						std::getline(std::cin, name);
						store.find_client(name);
					}
					else{
						std::cout << "\nVous n'avez pas saisi le bon chiffre, abandon de l'opération\n";
					}
				}
				else if(sous_menu == '4'){}
				else {
					menu = FAILURE;
				}

			} while(sous_menu > '0' && sous_menu < '4');
		}
		else if(menu == '3'){
			do{
				std::cout << "Vous êtes dans la section *Gestion des commandes*" << std::endl;
				std::cout << "Choisissez une action en entrant le chiffre correspondant : " << std::endl;
				std::cout << "1 : Affichage des commandes" << std::endl;
				std::cout << "2 : Mise à jour du statut des commandes" << std::endl;
				std::cout << "3 : Affichage des commandes d'un client" << std::endl;
				std::cout << "4 : Pour revenir en arrière" << std::endl;
				std::cout << "* : Une autre touche pour quitter !" << std::endl << std::endl;

				std::cin >> sous_menu;
				if(sous_menu == '1'){
					store.display_command();
				}
				else if(sous_menu == '2'){
					std::cout << "id de la commande à mettre à jour : ";
					int id;
					if(!(std::cin >> id)){
						std::cout << "Mauvaise manipulation, exit !!!\n";
						return EXIT_FAILURE;
					}
					std::cout << "Entrez D pour livré ou N pour non delivré : ";
					char state;
					std::cin >> state;
					auto cmd_list = store.commands();
					auto it = find_if(cmd_list.begin(), cmd_list.end(), [id](magasin::Command obj){return id == obj.id();});
					if(it != cmd_list.end()){
						if (state == 'D' || state == 'd'){
							store.update_command_status(*it, magasin::Status::delivered);
						}
						else if (state == 'N' || state == 'n'){
							store.update_command_status(*it, magasin::Status::not_delivered);
						} else{
							std::cout << "Opération abandonnée, votre saisi ne correspond ni à un D ni à un N" << std::endl;
						}
					}
					else {
						std::cout << "Aucune commande n'a cet id.\n";
					}
					std::cout << std::endl;
				}
				else if(sous_menu == '3'){
					std::cout << "Tapez 0 pour une recherche par id et 1 pour une recherche par nom ou prénom : ";
					char search;
					std::cin >> search;
					if(search == '0'){
						std::cout << "Veuillez saisir l'id du client : ";
						int id;
						if(!(std::cin >> id)){
							std::cout << "Mauvaise manipulation, exit !!!\n";
							return EXIT_FAILURE;
						}
						auto list = store.clients();
						auto it = person::find(list, id);
						store.display_client_command(*it);
						std::cout << std::endl;
					}
					else if(search == '1'){
						std::cout << "Veuillez saisir le nom ou le prénom du client : ";
						std::string name;
						std::cin >> name;
						auto cl_list = store.clients();
						auto it = std::find_if(cl_list.begin(), cl_list.end(), [name](const person::Client& obj){ return ( name == obj.firstname() || ( name == obj.lastname() ) );});
						store.display_client_command(*it);
						std::cout << std::endl;
					}
					else{
						std::cout << "\nVous n'avez pas saisi le bon chiffre, abandon de l'opération\n\n";
					}
				}
				else if(sous_menu == '4'){}
				else {
					menu = FAILURE;
				}
				
			} while(sous_menu > '0' && sous_menu < '4');
		}
		else{
			std::cout << "Merci de votre visite !" << std::endl;
		}
	}while((menu > '0' && menu < '4') || (sous_menu == '4') );
	
	return 0;
}
