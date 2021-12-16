# Enigma
Dans ce tp nous allons implémenter l'algorithme de chiffrement/déchiffrement de données de la machine Enigma utilisée par les allemands lors de la 2ème guerre mondiale. Cet algorithme a été étudié et déchiffré par Alan Turing et son équipe.


## Encrypt OK

Attribut
* plain (protected)
* cipher (protected)

Methodes ou fonctions(helper ou friend)
* constructor ok
* plain (getter) ok
* cipher (getter) ok
* encode (virtuel) ok
* decode (virtuel) ok
* read (helper) ok
* write (helper) ok

## Enigma herité de Encrypt OK

Attribut
* ring
* ring2

Methodes ou fonctions(helper ou friend)
* constructor ok
* encode (setter, override) ok
* decode (setter, override) ok
* transform_number (helper) ok
* transform_string (helper) ok