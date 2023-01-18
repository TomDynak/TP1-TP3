#include <iostream>
#include <vector>
#include "produit.h"
#include "client.h"

#ifndef MAGASIN_H
#define MAGASIN_H

namespace mag {
	class Magasin {
	public:
	Magasin();
	void addProd(Produit produit);
    void addClient(Client client);
	void AfficherListProd();
	void AfficherListClient();
	bool searchProd(std::string titre);
    bool searchClient(std::string ident);
	bool majProd(std::string titre);




	private:
	std::vector<Produit> _listeProduits;
	std::vector<Client> _listeClients;

	};
}
#endif