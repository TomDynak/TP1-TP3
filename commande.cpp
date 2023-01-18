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
		/*for(int i=0; i<_listeProduits.size(); i++){
			text += toString(_listeProduits.at(i));
		}*/
		for(int i=0; i<_titres.size(); i++){
			text += _titres.at(i) + " " + _descriptions.at(i) + " " + std::to_string(_quantites.at(i)) + " " + std::to_string(_prix.at(i)) + "\n";
		}
		return text;
	}

	int Commande::searchEqTitre(std::string titre){
		for (int i=0; i<_titres.size();i++){
			if(_titres.at(i) == titre){
				return i;
			}
		}
		return -1;
	}

	void Commande::addProduit(std::string titre, std::string description, unsigned int quantite, double prix){
		int a = searchEqTitre(titre);
		if(a > 0){ //Mise a jour
			_descriptions.at(a) = description;
			_quantites.at(a) = quantite;
			_prix.at(a) = prix;
		}else{
			_titres.push_back(titre);
			_descriptions.push_back(description);
			_quantites.push_back(quantite);
			_prix.push_back(prix);
		}
	}



	std::string toString(Commande c){
		std::string text = c.getIdent() + "\n" + c.listeProduit();
		return text;
	}
	std::ostream& operator<<(std::ostream& os, Commande& c){
		os << toString(c);
		return os;
	}
}