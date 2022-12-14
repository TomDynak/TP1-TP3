#include <vector>
#include "produit.h"
#include "client.h"
#include "commande.h"

class Magasin{
public:
	Magasin();
	void addProduit(produit::Produit newProd);
	void AllProducts();
private:

	std::vector<produit::Produit> _listeProduits;
	std::vector<client::Client> _listeClients;
	std::vector<commande::Commande> _listeCommandes;
};