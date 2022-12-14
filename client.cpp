#include <string>
#include "produit.h"
#include "client.h"
#include "commande.h"
#include "magasin.h"

namespace client{
	Client::CLient(std::string ident, std::string nom, std::string prenom) : _ident(ident), _nom(nom), _prenom(prenom) {
		
	}
}