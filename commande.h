#include <iostream>
#include <vector>
#include "produit.h"
#include "client.h"
#include "magasin.h"

#ifndef COMMANDE_H
#define COMMANDE_H

namespace mag {
	class Commande {
	public:
	Commande(std::string identClient = "anonymous");
	std::string getIdent();
	std::string listeProduit();
	private:
		std::string _identClient;
		std::vector<Produit> _listeProduits; //pas oublier que les produits sont copiés et que les changements ne se propageront pas
		bool _status; //true = livrée
	};
	std::string toString(Commande c);
	std::ostream& operator<<(std::ostream& os, Commande& c);
}
#endif