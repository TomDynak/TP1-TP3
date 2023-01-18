#include <iostream>
#include <string>
#include <vector>
#include "magasin.h"
#include "produit.h"
#include "commande.h"


namespace mag{
	Commande::Commande(std::string identClient) : _identClient(identClient), _status(false){

	}
	std::string Commande::getIdent(){
		return _identClient;
	}
	std::string Commande::listeProduit(){
		std::string text = "";
		for(int i=0; i<_listeProduits.size(); i++){
			text += toString(_listeProduits.at(i));
		}
		return text;
	}

	std::string toString(Commande c){
		std::string text = c.getIdent() + "\n" + c.listeProduit();
		//for qui prend les tostring des produits
		return text;
	}
	std::ostream& operator<<(std::ostream& os, Commande& c){
		os << toString(c);
		return os;
	}
}