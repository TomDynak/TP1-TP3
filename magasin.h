#include <iostream>
#include <vector>
#include "produit.h"
#include "client.h"
#include "commande.h"

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
	void AfficherListCommand();
	int searchProd(std::string titre);
    int searchClient(std::string ident);
	bool majProd(std::string titre);
	void addProdPanierClient(std::string ident, std::string titre);
	void suppPanierClient(std::string ident, std::string titre);
	void modifQuantPanierClient(std::string ident, std::string titre);
	void AfficherPanierClient();
	void addCommande(std::string ident);
	void validCommand(std::string ident);


	private:
	std::vector<Produit> _listeProduits;
	std::vector<Client> _listeClients;
	std::vector<Commande> _listeCommandes;

	std::vector<std::string> _titrePanier;
	std::vector<std::string> _descriptionPanier;
	std::vector<unsigned int> _quantitePanier;
	std::vector<double> _prixPanier;
	unsigned int _quantite;

	};
}
#endif