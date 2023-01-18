#include <iostream>
#include "magasin.h"
#include "produit.h"
#include "client.h"
#include "commande.h"

int main(){
	mag::Magasin Supermarche;
	mag::Produit test("PS5","Console de Jeux", 3, 500.50);
	mag::Produit test2("Nintendo Switch","Console de Jeux", 3, 400.50);
	mag::Client user1("tomdy","Tom","Dynak");
	mag::Client user2("nbar","Baréké","Ntawiniga");
	//test.modifQuantite(0);

	Supermarche.addProd(test);
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

	return 0;
}