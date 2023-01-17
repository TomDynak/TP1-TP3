#include <iostream>
#include <string>
#include "produit.h"
#include "client.h"

namespace mag {
Client::Client(std::string ident, std::string prenom, std::string nom): _ident(ident), _prenom(prenom), _nom(nom){

}
bool Client::addToPanier(mag::Produit produit){

	for(int i=0; i<_quantitePanier.size(); i++){
		if(produit.getTitre()==_titrePanier[i] && produit.getDescription()==_descriptionPanier[i]){
			_quantitePanier.at(i)++;
			std::cout <<"Produit dans le panier"<<std::endl;
			return false;
		}
	}

	if(produit.getQuantite()==0){
	std::cout <<"Produit indisponible"<<std::endl;
	}
	else{
	_titrePanier.push_back(produit.getTitre());
	_descriptionPanier.push_back(produit.getDescription());
	_quantitePanier.push_back(_quantite=1);
	_prixPanier.push_back(produit.getPrix());
	}
	return true;
}
	//}	
//}
void Client::getPanier(){
	for(int i=0; i<_titrePanier.size(); i++){
		std::cout << _titrePanier.at(i) << std::endl;
		std::cout << _descriptionPanier.at(i) << std::endl;
		std::cout << _quantitePanier.at(i) << std::endl;
		std::cout << _prixPanier.at(i) << std::endl << std::endl;
		}
	}

void Client::videPanier(){
	_titrePanier.clear();
	_descriptionPanier.clear(); 
	_quantitePanier.clear(); 
	_prixPanier.clear();
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

}