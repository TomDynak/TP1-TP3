#include <iostream>
#include <string>
#include "produit.h"
#include "client.h"

namespace mag {
Client::Client(std::string ident, std::string prenom, std::string nom): _ident(ident), _prenom(prenom), _nom(nom){

}
bool Client::addToPanier(mag::Produit produit){
	if(produit.getQuantite()==0){
	std::cout <<"Produit indisponible"<<std::endl;
	return false;
	}
	_panier.push_back(toString(produit));
	return true;
	
}

void Client::videPanier(){
	return _panier.clear();
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
	for(int i=0; i<_panier.size(); i++){
		std::cout << _panier.at(i) << std::endl;
		}
	}
}