#include <vector>
#include "produit.h"
#include "client.h"
#include "commande.h"

class Magasin{
public:
	Magasin();
private:

	std::vector<produit::Produit> _listeProduits;
	std::vector<client::Client> _listeClients;
	std::vector<commande::Commande> _listeCommandes;
};