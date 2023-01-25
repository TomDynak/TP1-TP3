#include <iostream>
#include <string>
#include <vector>
#include "magasin.h"
#include "produit.h"
#include "client.h"
#include "commande.h"

namespace mag{

	Magasin::Magasin(){

	}
	void Magasin::addProd(mag::Produit produit){
		_listeProduits.push_back(produit);
	}
  void Magasin::addClient(mag::Client client){
    //Vérifier avec searchClient si il n'y est pas déjà?
		_listeClients.push_back(client);
	}

	void Magasin::AfficherListProd(){
		for (int i=0; i<_listeProduits.size(); i++){
			std::cout<<_listeProduits.at(i)<<std::endl<<std::endl;
		}
	}
	void Magasin::AfficherListClient(){
		for (int i=0; i<_listeClients.size(); i++){
			std::cout<<_listeClients.at(i)<<std::endl<<std::endl;
		}
	}
	int Magasin::searchProd(std::string titre){
		for (int i=0; i<_listeProduits.size(); i++){
			if(titre==_listeProduits.at(i).getTitre()){
				std::cout<<_listeProduits.at(i)<<std::endl<<std::endl;
				return i;
			}							
		}
		std::cout<<"Pas trouvé"<<std::endl;
		return -1;		
	}
  int Magasin::searchClient(std::string ident){
		for (int i=0; i<_listeClients.size(); i++){
			if(ident==_listeClients.at(i).getIdent()){
				std::cout << _listeClients.at(i)<<std::endl<<std::endl;
				return i;
			}							
		}
		std::cout<<"Pas trouvé"<<std::endl;
		return -1;		
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
	void Magasin::addProdPanierClient(std::string ident, std::string titre){
		int a = searchClient(ident);
		int b= searchProd(titre);
		if(a==-1 || b==-1){

		}
		else{
			_listeClients.at(a).addToPanier(_listeProduits.at(b));
		}
		
	}
	void Magasin::suppPanierClient(std::string ident, std::string titre){
		int a = searchClient(ident);
		int b= searchProd(titre);
		if(a==-1 || b==-1){

		}
		else{
			_listeClients.at(a).suppProduitPanier(_listeProduits.at(b));
		}

	}

	void Magasin::modifQuantPanierClient(std::string ident, std::string titre){
		int a = searchClient(ident);
		int b= searchProd(titre);
		if(a==-1 || b==-1){

		}
		else{
			_listeClients.at(a).modifQuantPanier(_listeProduits.at(b));
		}

	}
	void Magasin::AfficherPanierClient(){
		for (int i=0; i<_listeClients.size(); i++){
			_listeClients.at(i).getPanier();
		}
	}

	void Magasin::addCommande(std::string ident){ //Recupere le panier
        mag::Commande c(ident);
    Client client = _listeClients.at(searchClient(ident)); // On fait une copie mais on la modifie pas donc ça va
        _listeClients.at(searchClient(ident));
        for(int i=0; i < client.getPanierSize(); i++){
            c.addProduit(client.getTitrePanier(i),client.getDescriptionPanier(i),client.getQuantitePanier(i),client.getPrixPanier(i));
        }
    _listeCommandes.push_back(c);
    }

   void Magasin::validCommand(std::string ident){
   	Commande c(ident);
   		for (int i=0; i<_listeCommandes.size(); i++){
   			if(c.getIdent()==_listeCommandes.at(i).getIdent()){
   					_listeCommandes.at(i).addTrue();
   				
   			}
   		
   		}
   		
   }
}