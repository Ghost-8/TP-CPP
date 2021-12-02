# Description des classes (analyse du problème)


## Produits OK					

Varibles :
* id : int 
* titre : string
* description : string
* quantité : int 
* prix : float

Methodes ou fonctions (helper ou friend) :
* constructor (with assert)
* Getters
* update quantité (method)
* surcharge operator <<

## Clients

Varibles :
* id : int
* prenom : string
* nom : string
* panier : vector  --> sera vidé lorsque la commande sera validée

Methodes ou fonctions (helper ou friend) :
* constructor (with assert)
* Getters
* Afficher le panier (method) ok
* ajout au panier () ok
* vider le panier ok
* modifier la quatité d'un produit ok
* supprimer un produit	  ok
* surcharge operator <<   ok

## Commandes (Avant de valider une commande il faut s'assurer que le produit est disponible)

Varibles :
* id_client : int (attribut id d'un objet client)
* produits commandés : vector de id_produit
* statut : enum(livrée | pas livrée) 

Methodes ou fonctions (helper ou friend) :
* constructor (with assert)
* surcharge operator << 

## Magasin

Variables : 
* produits : vector
* clients : vector
* commande : vector

Methodes ou fonctions (helper ou friend) :
* constructor (with assert)
* Ajouter nouveau produit au magasin (method) ok
* Afficher tous les produits (method) ok
* update product quantity (method) ok
* Ajout nouveau client (method) ok
* Afficher tous les clients (method) ok
* Afficher client selon le nom ou l'id passé en paramètre ok
* Ajouter un produit au panier d'achat d'un client 
* Supprimer un produit du panier d'un client 
* Modifier la quantité d'un produit du panier d'un client
* Valider une commande ok
* update status commande ok
* Afficher toutes les commandes passées ok
* Afficher les commandes d'un client donné