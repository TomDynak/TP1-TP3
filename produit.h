#include <string>

namespace produit{
class Produit {
public:
Produit(std::string titre, std::string description, unsigned int quantite, double prix);
std::string getTitre();
std::string getDescription();
unsigned int getQuantite();
double getPrix();
void modifQuantite(unsigned int quantite);
std::string Afficher(Produit p);

private:
std::string _titre;
std::string _description;
unsigned int _quantite;
double _prix;

};
}