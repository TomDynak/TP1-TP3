#include <iostream>
#include <string>
#include <vector>
#include "produit.h"
#include "commande.h"
#include "client.h"
#include "magasin.h"


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
		if(a > 0){ //Mise a jour si on retrouve le même titre, donc le même produit
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
	void Commande::addProduit(Produit p){
		int a = searchEqTitre(p.getTitre());
		if(a > 0){ //Mise a jour si on retrouve le même titre, donc le même produit
			_descriptions.at(a) = p.getDescription();
			_quantites.at(a) += 1;
			_prix.at(a) = p.getPrix();
		}else{
			_titres.push_back(p.getTitre());
			_descriptions.push_back(p.getDescription());
			_quantites.push_back(1);
			_prix.push_back(p.getPrix());
		}
		}

		void Commande::addTrue(){
			_status=true;
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