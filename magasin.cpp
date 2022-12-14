#include <vector>
#include "produit.h"
#include "client.h"
#include "commande.h"

Magasin::Magasin(){
	
}

void Magasin::addProduit(produit::Produit newProd){
	_listeProduits.push_back(newProd);
}
void Magasin::allProducts(){
	for(int i=0, i < _listeProduits.size(); i++){
		std::cout << _listeProduits.at(i) << std::endl 
	}
}