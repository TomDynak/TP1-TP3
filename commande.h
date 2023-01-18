#include <iostream>
#include <vector>
#include "produit.h"
#include "client.h"

#ifndef COMMANDE_H
#define COMMANDE_H

namespace mag {
	class Commande {
	public:
		Commande(std::string identClient = "anonymous");
		std::string getIdent();
		std::string listeProduit();
		void addProduit(std::string titre, std::string description, unsigned int quantite, double prix);
		void addProduit(Produit p);
	private:
		int searchEqTitre(std::string titre); //Donne la position de titre doublon, pour mettre a jour un produit existant?
		std::string _identClient;
		bool _status; //true = livrée
		std::vector<std::string> _titres;
		std::vector<std::string> _descriptions;
		std::vector<unsigned int> _quantites;
		std::vector<double> _prix;
	};
	std::string toString(Commande c);
	std::ostream& operator<<(std::ostream& os, Commande& c);
}
#endif