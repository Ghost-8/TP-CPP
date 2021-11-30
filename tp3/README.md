# Description des classes (analyse du problème)


## Produits

Varibles :
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
* id : 
* prenom : string
* nom : string
* panier : vector  --> sera vidé lorsque la commande sera validée

Methodes ou fonctions (helper ou friend) :
* constructor (with assert)
* Getters
* Setters
* Afficher le panier (method)
* ajout au panier ()
* vider le panier
* modifier la quatité d'un produit
* supprimer un produit
* surcharge operator <<  

## Commandes (Avant de valider une commande il faut s'assurer que le produit est disponible)

Varibles :
* id_client : int (attribut id d'un objet client)
* produits commandés : vector
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
* Ajouter nouveau produit au magasin (method)
* Afficher tous les produits (method)
* update product quantity (method)
* Ajout nouveau client (method)
* Afficher tous les clients (method)
* Afficher client selon le nom ou l'id passé en paramètre 
* Ajouter un produit au panier d'achat d'un client
* Supprimer un produit du panier d'un client 
* Modifier la quantité d'un produit du panier d'un client
* Valider une commande 
* update status commande
* Afficher toutes les commandes passées
* Afficher les commandes d'un client donné