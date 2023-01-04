#include <iostream>
#include <string>
#include "produit.h"

namespace mag{
Produit::Produit(std::string titre, std::string description, unsigned int quantite, double prix): _titre(titre), _description(description), _quantite(quantite), _prix(prix){

}
void Produit::modifQuantite(unsigned int quantite){
	_quantite=quantite;
}



//Fonctions getters
std::string Produit::getTitre(){
	return _titre;
	}
std::string Produit::getDescription(){
	return _description;
	}
unsigned int Produit::getQuantite(){
	return _quantite;
	}
double Produit::getPrix(){
	return _prix;
	}
std::string toString(Produit p){
	return p.getTitre() + "\n" + p.getDescription() + "\n" + std::to_string(p.getQuantite()) + "\n" + std::to_string(p.getPrix());
}
std::ostream& operator<<(std::ostream& os, Produit& p){
	os << toString(p);
	return os;
};
}