#include <iostream>
#include <string>
#include <vector>
#include "magasin.h"

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
	void Magasin::searchProd(std::string titre){
		for (int i=0; i<_listeProduits.size(); i++){
			if(titre==_listeProduits.at(i).getTitre()){
				std::cout<<_listeProduits.at(i)<<std::endl<<std::endl;
			}
		}
	}
}