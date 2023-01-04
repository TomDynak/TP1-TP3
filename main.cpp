#include <iostream>
#include "magasin.h"
#include "produit.h"

int main(){
	mag::Magasin Vide();
	mag::Produit test("PS5","Console de Jeux", 3, 500);
	std::cout << test.getQuantite() << std::endl;
	test.modifQuantite(2);
	std::cout << test.getQuantite() << std::endl;

	return 0;
}