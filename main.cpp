#include <iostream>
#include "magasin.h"
#include "produit.h"
#include "client.h"
#include "commande.h"


int main(){

int condition=0;
int condition2=1;
std::string user;
std::string nom, description;
unsigned int quantite;
float prix;

mag::Magasin Supermarche;
mag::Produit test("PS5","Console de Jeux", 3, 500.50);
mag::Produit test2("Nintendo Switch","Console de Jeux", 3, 400.50);
mag::Client user1("tomdy","Tom","Dynak");
mag::Client user2("nbar","Baréké","Ntawiniga");
mag::Commande c("tomdy");

do{
	
if(condition2==1){
	std::cout<<"=================================Menu=====================================\n\nGestion du magasin (1) || Gestion des utilisateurs (2) || Gestion des commandes (3) || Quitter (0)"<<std::endl;
	std::cin>>condition;
	if(condition>0){
		condition2++;
	}
	else{
		condition2=0;
	}
}


if(condition==1 && condition2==2){
	std::cout<<"==================================Gestion Magasin====================================\n\nAjouter les commandes (1) || Ajout d'un produit (2) || Affichage des produits (3) || Retourner au menu principal (0)"<<std::endl;
	std::cin>>condition;
	if(condition>0){
		condition2++;
	}
	else{
		condition2--;
	}
	}
if(condition==1 && condition2==3){
	std::cout<<"Entrer le nom d'utilisateur de la commande :"<<std::endl;
	std::cin>>user;
	Supermarche.addCommande(user);
	Supermarche.AfficherCommandeClient(user);
	}
if(condition==2 && condition2==3){
	std::cout<<"Rentrer le nom du produit"<<std::endl;
	std::cin>>nom;
	std::cout<<"Rentrer la description du produit"<<std::endl;
	std::cin>>description;
	std::cout<<"Rentrer la quantité du produit"<<std::endl;
	std::cin>>quantite;
	std::cout<<"Rentrer le prix du produit"<<std::endl;
	std::cin>>prix;

	mag::Produit produit(nom, description, quantite, prix);
	Supermarche.addProd(produit);
	condition2=2;
	condition=1;
	}
if(condition==3 && condition2==3){
	Supermarche.AfficherListProd();
	condition2=2;
	condition=1;
}
	
if(condition==2 && condition2==2){
	std::cout<<"==================================Gestion Utilisateurs====================================\n\nAjouter des utilisateurs (1) || Ajout d'un produit (2) || Affichage des produits (3) || Retourner au menu principal (0)"<<std::endl;
	std::cin>>condition;
	if(condition>0){
		condition2++;
	}
	else{
		condition2--;
	}
	}	
	
	



	//test.modifQuantite(0);

/*	Supermarche.addProd(test);
	Supermarche.addProd(test2);
	Supermarche.addClient(user1);
	Supermarche.addClient(user2);

	Supermarche.AfficherListProd();

	//Supermarche.searchProd("Nintendo Switch");

	//Supermarche.majProd("PS5");
	//Supermarche.majProd("bruh");
	//Supermarche.searchProd("PS5");
	//user1.addToPanier(test);
	//user1.addToPanier(test);
	//user1.addToPanier(test2);
	//user1.getPanier();
	//user1.modifQuantPanier("PS5");
	//user1.getPanier();
	//user1.suppProduitPanier("Nintendo Switch");
	//user1.getPanier();
	//user1.videPanier();
	//user1.getPanier();
	//Supermarche.AfficherListClient();

	Supermarche.addProdPanierClient("tomdy","PS5");
	std::cout << "---------------" << std::endl;
	Supermarche.AfficherPanierClient();
	std::cout<<c;

	return 0;*/}
	while(condition2!=0);
	return 0;
}
