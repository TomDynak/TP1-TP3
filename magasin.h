#include <iostream>
#include <vector>
#include "produit.h"

#ifndef MAGASIN_H
#define MAGASIN_H

namespace mag {
	class Magasin {
	public:
		Magasin();
		void addProd(Produit produit);
		void AfficherListProd();
		void searchProd(std::string titre);



	private:
	std::vector<Produit> _listeProduits;

	};
}
#endif