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

bool Client::modifQuantPanier(mag::Produit produit){
	for (int i=0; i<_titrePanier.size(); i++){
		if(produit.getTitre()==_titrePanier.at(i)){
		unsigned int quantite;
		std::cout<<"Quelle est la nouvelle quantité de ce produit : "<<produit.getTitre()<<std::endl;
		std::cin >> quantite;
		_quantitePanier.at(i)=quantite;
		return true;
		}
	}
		std::cout<<"Pas trouvé"<<std::endl;	
		return false;
	}

bool Client::suppProduitPanier(mag::Produit produit){
	for (int i=0; i<_titrePanier.size(); i++){
		if(produit.getTitre()==_titrePanier.at(i)){
			
		_titrePanier.erase(_titrePanier.begin()+i);
		_descriptionPanier.erase(_descriptionPanier.begin()+i);
		_quantitePanier.erase(_quantitePanier.begin()+i);
		_prixPanier.erase(_prixPanier.begin()+i);
		return true;
		}
	}
		std::cout<<"Pas trouvé"<<std::endl;	
		return false;
	}

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

std::string Client::getTitrePanier(int a){
	return _titrePanier.at(a);
}

std::string Client::getDescriptionPanier(int a){
	return _descriptionPanier.at(a);
}

unsigned int Client::getQuantitePanier(int a){
	return _quantitePanier.at(a);
}

double Client::getPrixPanier(int a){
	return _prixPanier.at(a);
}

unsigned int Client::getPanierSize(){
	return _titrePanier.size();
}

std::string toString(Client c){
	return c.getIdent() + "\n" + c.getPrenom() + "\n" + c.getNom()+ "\n" + c.getPanier(); //ajouter le panier
	}
std::ostream& operator<<(std::ostream& os, Client& c){
	os << toString(c);
	return os;
	}

}
