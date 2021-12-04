# Description des classes (analyse du problème)


## Produits OK					

Varibles :
* id : int 
* titre : string
* description : string
* quantité : int 
* prix : float

Methodes ou fonctions (helper ou friend) :
* constructor ok
* Getters ok
* update quantité (method) ok
* surcharge operator << ok

## Clients OK

Varibles :
* id : int
* prenom : string
* nom : string
* panier : vector  --> sera vidé lorsque la commande sera validée

Methodes ou fonctions (helper ou friend) :
* constructor ok
* Getters ok
* Afficher le panier (method) ok
* ajout au panier () ok
* vider le panier ok
* modifier la quatité d'un produit ok
* supprimer un produit	  ok
* surcharge operator <<   ok

## Commandes OK
(Avant de valider une commande il faut s'assurer que le produit est disponible)

Varibles :
* id_client : int (attribut id d'un objet client)
* produits commandés : vector de id_produit
* statut : enum(livrée | pas livrée) 

Methodes ou fonctions (helper ou friend) :
* constructor ok
* surcharge operator <<  ok

## Magasin 

Variables : 
* produits : vector
* clients : vector
* commande : vector

Methodes ou fonctions (helper ou friend) :
* constructor ok
* Ajouter nouveau produit au magasin (method) ok
* Afficher tous les produits (method) ok
* update product quantity (method) ok
* Ajout nouveau client (method) ok
* Afficher tous les clients (method) ok
* Afficher client selon le nom ou l'id passé en paramètre ok
* Ajouter un produit au panier d'achat d'un client ok
* Supprimer un produit du panier d'un client ok
* Modifier la quantité d'un produit du panier d'un client ok
* Valider une commande ok
* update status commande ok
* Afficher toutes les commandes passées ok
* Afficher les commandes d'un client donné ok