#include <iostream>
#include "magasin.h"
#ifndef PRODUIT_H
#define PRODUIT_H

namespace mag{
	class Produit {
	public:
		Produit(std::string titre, std::string description, unsigned int quantite, double prix);

	private:
		std::string _titre;
		std::string _description;
		unsigned int _quantite;
		double _prix;
	};
}

#endif