#include "emprunt.h"


namespace bibli{
	Emprunt::Emprunt(date::Date dateEmprunt, std::string isbn, std::string identifiantLecteur) : _dateEmprunt(dateEmprunt), _isbn(isbn), _identifiantLecteur(identifiantLecteur), _actif(true) {

	}
	
	std::string Emprunt::getISBN() const {
	        return _isbn;
	}

	std::string Emprunt::getIdent() const {
	        return _identifiantLecteur;
	}

  bool Emprunt::getState() const{
    return _actif;
  }
	void Emprunt::disable(){
		_actif = false;
	}
}