#include <iostream>
#include "magasin.h"
#include "produit.h"

int main(){
	mag::Magasin Supermarche;
	mag::Produit test("PS5","Console de Jeux", 3, 500);
	mag::Produit test2("Nintendo Switch","Console de Jeux", 3, 400);
	test.modifQuantite(2);
	std::cout << test <<std::endl;

	Supermarche.addProd(test);
	Supermarche.addProd(test2);

	Supermarche.AfficherListProd();

	Supermarche.searchProd("Nintendo Switch");

	return 0;
}