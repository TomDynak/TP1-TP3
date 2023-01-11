#include <iostream>

#ifndef PRODUIT_H
#define PRODUIT_H

namespace mag{
	class Produit {
	public:
		Produit(std::string titre, std::string description, unsigned int quantite, double prix);
		void modifQuantite(unsigned int quantite);
		std::string getTitre();
		std::string getDescription();
		unsigned int getQuantite();
		double getPrix();

	private:
		std::string _titre;
		std::string _description;
		unsigned int _quantite;
		double _prix;
	};
	std::string toString(Produit p);
	std::ostream& operator<<(std::ostream& os, Produit& p);
}

#endif