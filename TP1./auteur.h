#ifndef Auteur_H
#define Auteur_H
#include "date.h"

namespace bibli{
	class Auteur {
	public:
		Auteur(std::string identifiant = "00000000", std::string nom = "DuMoulin", std::string prenom = "Jean", date::Date naissance = date::Date(1,1,1000));
		std::string getNom() const;
		std::string getPrenom() const;
		std::string getNomEntier() const;
		std::string getIdent() const;

	private:
		std::string _identifiant;
		std::string _nom;
		std::string _prenom;
		date::Date _naissance;

	};

	bool operator == (const Auteur& a1, const Auteur& a2);

	std::ostream& operator<<(std::ostream& os, Auteur& auteur);
}

#endif