#include <string>

namespace produit{
	Produit::Produit(std::string titre, std::string description, unsigned int quantite, double prix) : _titre(titre), _description(description), _quantite(quantite), _prix(prix) {
	}
	void Produit::modifQuantite(unsigned int quantite){
		_quantite=quantite;
	}
	std::string Produit::getTitre(){
		return _titre;
	}
	std::string Produit::getDescription(){
		return _description;
	}
	unsigned int Produit::getQuantite(){
		return _quantite;
	}
	double Produit::getPrix(){
		return _prix;
	}
	std::string Afficher(Produit p){
		return std::string p.getTitre + "\n" + std::string p.getDescription + "\n" + std::toString(p.getQuantite) + std::toString(p.getPrix) + "\n" + "\n" ;
	}
	
	std::ostream& operator<<(std::ostream& os, Produit& p){
	os << p.Afficher();
	return os;
}
}