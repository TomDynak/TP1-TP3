#ifndef Lecteur_H
#define Lecteur_H
#include "livre.h"
#include <string>
#include <vector>

namespace bibli {
class Lecteur {
public:
	Lecteur(std::string ident = "00000000", std::string nom = "Dynak", std::string prenom = "Tom");
 	std::string getIdent() const;
    std::string getNom() const;
    std::string getPrenom() const;
    void addToList(std::string isbn);
    void afficherLecteur() const;
    bool oublier(std::string isbn); // vide _listeisbn



private:
	std::string _ident;
	std::string _nom;
	std::string _prenom;
	std::vector<std::string>_listeisbn;


};

std::ostream& operator<<(std::ostream& os, Lecteur& lecteur);
}

#endif