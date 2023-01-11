#include <iostream>
#include <string>
#include "produit.h"
#include "client.h"

namespace mag {
Client::Client(std::string ident, std::string prenom, std::string nom, std::string panier): _ident(ident), _prenom(prenom), _nom(nom), _panier(panier){

}

std::string Client::getIdent(){
	return _ident;
}
std::string Client::getPrenom(){
	return _prenom;
}
std::string Client::getNom(){
	return _nom;
}
std::string Client::getPanier(){
	return _panier;
	}

}