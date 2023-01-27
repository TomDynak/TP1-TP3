#ifndef Bibliotheque_H
#define Bibliotheque_H
#include <vector>
#include "lecteur.h"
#include "auteur.h"
#include "livre.h"
#include "emprunt.h"

namespace bibli{
	class Bibliotheque{
		public:
			Bibliotheque();
			void addLecteur(Lecteur lecteur);
			void addAuteur(Auteur auteur);
			void addLivre(Livre livre);
			void addEmprunt(Emprunt& emprunt);
			void emprunter(Livre& livre, Lecteur& lecteur);
			void restituer(std::string isbn, Lecteur& lecteur);
			void searchLivre(Auteur& auteur) ; //Affiche les livres de l'auteur
      void searchLivreDispo() const; //Affiche les livres de _listeLivre 
      void searchLivreLecteur(std::string ident) const;
      void classementLecteur() const;
  
		private:
			std::vector<Lecteur> _listeLecteur;
			std::vector<Auteur> _listeAuteur;
			std::vector<Livre> _listeLivre;
			std::vector<Emprunt> _listeEmprunt;
			//Emprunt searchEmprunt(std::string isbn, std::string ident) const;
      //Retourner l'Emprunt ne marchait pas mais je pouvait facilement donner la position dans la liste
      int searchEmprunt(std::string isbn, std::string ident) const; 
			Livre searchLivre(std::string isbn) const; // Retrouve le livre dans _listeLivre a partir de l'isbn
      int findListLivrePos(std::string isbn) const;
      int nombreLivreEmprunter(std::string ident) const;
      Lecteur searchLecteur(std::string ident) const;
      
	};

}
#endif