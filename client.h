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
	std::string getPanier();

	void videPanier();
	bool addToPanier(mag::Produit produit);

private:
	std::string _ident;
	std::string _prenom;
	std::string _nom;
	std::vector<std::string> _panier;
};

}

#endif