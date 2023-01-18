#include <iostream>
#include <string>
#include <vector>
#include "produit.h"

#ifndef CLIENT_H
#define CLIENT_H

namespace mag {

class Client {
public:
	Client(std::string ident, std::string prenom, std::string nom);
	std::string getIdent();
	std::string getPrenom();
	std::string getNom();
	std::string getTitrePanier(int a);
	std::string getDescriptionPanier(int a);
	unsigned int getQuantitePanier(int a);
	double getPrixPanier(int a);
	void getPanier();
	bool modifQuantPanier(Produit produit);
	void videPanier();
	bool addToPanier(Produit produit);
	bool suppProduitPanier(Produit produit);
	unsigned int getPanierSize();

private:
	std::string _ident;
	std::string _prenom;
	std::string _nom;

	std::vector<std::string> _titrePanier;
	std::vector<std::string> _descriptionPanier;
	std::vector<unsigned int> _quantitePanier;
	std::vector<double> _prixPanier;
	unsigned int _quantite;
};
	std::string toString(Client c);
	std::ostream& operator<<(std::ostream& os, Client& c);
}

#endif