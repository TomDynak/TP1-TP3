#include <iostream>
#include "magasin.h"
#include "produit.h"

int main(){
	mag::Magasin Vide();
	mag::Produit test("PS5","Console de Jeux", 3, 500);
	test.modifQuantite(2);
	std::cout << test <<std::endl;

	return 0;
}