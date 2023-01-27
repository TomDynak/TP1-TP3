#ifndef Livre_H
#define Livre_H
#include <string>
#include <vector>
#include "date.h"
#include "auteur.h"

namespace bibli{
    class Livre{
        public:
        Livre(std::string titre = "Hypersensible & introverti", Auteur auteur = Auteur("00000000", "DuMoulin", "Jean"), std::string genre = "Heroic Fantasy", date::Date dateParution= date::Date(1,1,1000), std::string isbn = "0000000000", bool _dispo = true);
        std::string getTitre() const;
        std::string getAuteur() const;
        Auteur& getAuteurC() ;
        std::string getGenre() const;
        std::string getISBN() const;
        date::Date& getDate();
        bool getDispo() const;
        void setDispo(bool a);

        void addToList(std::string id);
        void printEmprunt() const;
        void printVar() const;
        
        private:
        std::string _titre;
        Auteur _auteur; // comment j'initialise si je met cette variable en reference?
        std::string _genre;
        date::Date _date;
        std::string _isbn;
        std::vector<std::string> _listeID; //liste d'identifiant d'emprunteur
        bool _dispo;

    };

    std::string toString(Livre livre);

    std::ostream& operator<<(std::ostream& os, Livre& livre);
}

#endif