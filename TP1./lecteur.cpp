#include <iostream>
#include "lecteur.h"
#include <string>
#include <vector>

namespace bibli{
	Lecteur::Lecteur(std::string ident, std::string nom, std::string prenom): _ident(ident), _nom(nom), _prenom(prenom) {

	}

    std::string Lecteur::getIdent() const {
        return _ident;
    }

    std::string Lecteur::getNom() const {
        return _nom;
    }

    std::string Lecteur::getPrenom() const {
        return _prenom;
    }

 	void Lecteur::addToList(std::string isbn){
 		_listeisbn.push_back(isbn);
 	}

 	void Lecteur::afficherLecteur() const {
 		 std::cout << getIdent() << " " << getNom() << " " << getPrenom() << std::endl;
	}

	bool Lecteur::oublier(std::string isbn){
		for (int i = 0; i < _listeisbn.size(); i++){
			if (_listeisbn.at(i) == isbn){
				_listeisbn.erase(_listeisbn.begin()+i);
				return 1;
			}
		}
		return 0;
	}

	std::ostream& operator<<(std::ostream& os, Lecteur& lecteur){
		os << lecteur.getIdent() << " " << lecteur.getPrenom() << " " << lecteur.getNom() << std::endl;
		return os;
	}
}