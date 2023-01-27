#include <iostream>
#include "livre.h"

namespace bibli{
    Livre::Livre(std::string titre, Auteur auteur, std::string genre, date::Date dateParution, std::string isbn, bool dispo): _titre(titre), _auteur(auteur), _genre(genre), _date(dateParution), _isbn(isbn), _dispo(dispo) {
        
    }

    std::string Livre::getTitre() const {
        return _titre;
    }

    std::string Livre::getAuteur() const {
        return _auteur.getNomEntier();
    }

    Auteur& Livre::getAuteurC() {
        return _auteur;
    }

    std::string Livre::getGenre() const {
        return _genre;
    }

    date::Date& Livre::getDate(){
        return _date;
    }

    std::string Livre::getISBN() const {
        return _isbn;
    }

    bool Livre::getDispo() const {
        return _dispo;
    }

    void Livre::setDispo(bool a) {
        _dispo = a;
    }

    void Livre::addToList(std::string id){
        _listeID.push_back(id);
    }

    void Livre::printEmprunt() const {
        for(int i=0; i < _listeID.size();i++){
            std::cout << _listeID.at(i) << std::endl;
        }
    }

    void Livre::printVar() const {
        std::cout << getTitre() << " " << getAuteur() << " " << getGenre() << " " << getISBN() << std::endl;
    }

    std::string toString(Livre livre){
        return livre.getTitre() + " " + livre.getAuteur() + " " + livre.getGenre() + " " + toString(livre.getDate());
    }

    std::ostream& operator<<(std::ostream& os, Livre& livre){
        os << livre.getTitre() << " " << livre.getAuteur() << " " << livre.getGenre() << " " << livre.getDate() << std::endl;
        return os;
    }


}