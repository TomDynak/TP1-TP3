#include <iostream>
#include <string>
#include "produit.h"

#ifndef CLIENT_H
#define CLIENT_H

namespace mag {

class Client {
public:
	Client(std::string ident, std::string prenom, std::string nom, std::string panier);
	std::string getIdent();
	std::string getPrenom();
	std::string getNom();
	std::string getPanier();

private:
	std::string _ident;
	std::string _prenom;
	std::string _nom;
	std::string _panier;
};

}

#endif