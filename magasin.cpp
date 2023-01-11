#include <iostream>
#include <string>
#include <vector>
#include "magasin.h"
#include "produit.h"

namespace mag{

	Magasin::Magasin(){

	}
	void Magasin::addProd(mag::Produit produit){
		_listeProduits.push_back(produit);
	}

	void Magasin::AfficherListProd(){
		for (int i=0; i<_listeProduits.size(); i++){
			std::cout<<_listeProduits.at(i)<<std::endl<<std::endl;
		}
	}
	bool Magasin::searchProd(std::string titre){
		for (int i=0; i<_listeProduits.size(); i++){
			if(titre==_listeProduits.at(i).getTitre()){
				std::cout<<_listeProduits.at(i)<<std::endl<<std::endl;
				return true;
			}							
		}
		std::cout<<"Pas trouvé"<<std::endl;
		return false;		
	}
	bool Magasin::majProd(std::string titre){
		for (int i=0; i<_listeProduits.size(); i++){
			if(titre==_listeProduits.at(i).getTitre()){
			unsigned int quantite;
			std::cout<<"Quelle est la nouvelle quantité de ce produit : "<<titre<<std::endl;
			std::cin >> quantite;
			_listeProduits.at(i).modifQuantite(quantite);
			return true;
		}
	}
		std::cout<<"Pas trouvé"<<std::endl;	
		return false;
	}
}