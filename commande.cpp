#include "client.h"
#include <vector>
#include <string>

namespace commande{
	Commande::Commande(client::Client clientCommand, std::vector <std::string> listeProduit, bool status) : _clientCommand(clientCommand), _listeProduit(listeProduit), _status(status) {

	}
}