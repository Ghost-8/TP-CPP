# Enigma
Dans ce tp nous allons implémenter l'algorithme de chiffrement/déchiffrement de données de la machine Enigma utilisée par les allemands lors de la 2ème guerre mondiale. Cet algorithme a été étudié et déchiffré par Alan Turing et son équipe.


## Encrypt

Attribut
* plain (protected)
* cypher (protected)

Methodes ou fonctions(helper ou friend)
* plain (getter)
* cipher (getter)
* decode (virtuel)
* encode (virtuel)

## Enigma

Attribut

Methodes ou fonctions(helper ou friend)
* plain (getter)
* cipher (getter)
* decode (setter, override)
* read (helper)
* write (helper)
* transform_number (friend)
* transform_char (friend) 
* surcharge operator<< (helper)

* encode (setter, override)
Lecture dans un fichier (test si tout s'est bien passé : totalité du fic et d'une ligne)
Traitements ligne par ligne
La ligne extraite est mise dans un conteneur
Les blancs sont ignorés
Le fichier ne devra contenir que des minuscules pour un début 
La correspondance de chaque lettre en chiffre sera mise dans une case du conteneur (Les traitements s'effectueront sur des chiffres)
Ce conteneur sera appelé "in" pour la suite

Anneau : 
Les anneaux seront différents et desordonnés (t1 pour anneau 1 et t2 pour anneau 2)
La dispositions des lettres est predefinie dans le programme
Il y a une rotation ou plus techniquement une incrementation du compteur de l'anneau lorsqu'une lettre est chiffrée
Le premier fait 26 rotate avant que le deuxième ne fasse une rotate
C'est la corresondance dans le deuxième anneau qui sera transmise

Traitrements : 
2 boucles imbriquées feront le codage
La boucle extérieure (anneau 2) :
	Conditions d'arrêts : 
		contenu de "in" totalement traité
	traitements :
		i2 += 1
		i2 %= 26
		i1 %= 26
La boucle intérieure (anneau 1)
	Conditions d'arrêts :
		contenu de "in" totalement traité
		i1 >= 26
	traitements :
		pos1 = in[i]
		pos2 = t1[(pos1+i1)%26]
		cipher_letter = t2[(pos2+i2)%26]
		cipher+=cipher_letter
		i1+=1

Après le traitement d'une ligne on stocke le résultat dans un fichier, qui recevra la totalité des données