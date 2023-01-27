#ifndef Emprunt_H
#define Emprunt_H
#include "date.h"

namespace bibli{
	class Emprunt{
		public:
		Emprunt(date::Date dateEmprunt = date::Date(1,1,1000), std::string isbn = "0000000000", std::string identifiantLecteur = "00000000");
		std::string getISBN() const;
		std::string getIdent() const;
    bool getState() const; // Retourne _actif
		void disable(); // _actif = false

		private:
			date::Date _dateEmprunt;
			std::string _isbn;
			std::string _identifiantLecteur;
			bool _actif;

	};
}
#endif