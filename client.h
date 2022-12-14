#include <string>

namespace client{
class Client {
public:
Client(std::string ident, std::string nom, std::string prenom);
 	std::string getIdent() const;
    std::string getNom() const;
    std::string getPrenom() const;


private:
	std::string _ident;
	std::string _nom;
	std::string _prenom;

};
}