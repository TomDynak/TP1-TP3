#include "client.h"
#include <vector>
#include <string>

namespace commande {
class Commande{

public:
Commande(client::Client clientCommand = client::Client("tomdy","Tom","Dynak"), std::vector <std::string> listeProduit, bool status);

private:
client::Client _clientCommand;
std::vector <std::string> _listeProduit;
bool _status;

};
}