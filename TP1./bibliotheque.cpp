#include <iostream>
#include <vector>
#include "date.h"
#include "bibliotheque.h"
#include "lecteur.h"
#include "auteur.h"
#include "livre.h"
#include "emprunt.h"

namespace bibli{
	Bibliotheque::Bibliotheque(){
	}

	void Bibliotheque::addLecteur(bibli::Lecteur lecteur){
		_listeLecteur.push_back(lecteur);
	}

	void Bibliotheque::addAuteur(bibli::Auteur auteur){
		_listeAuteur.push_back(auteur);
	}

	void Bibliotheque::addLivre(bibli::Livre livre){
		_listeLivre.push_back(livre);
	}

	void Bibliotheque::addEmprunt(Emprunt& emprunt){
		_listeEmprunt.push_back(emprunt);
	}

	void Bibliotheque::emprunter(Livre& livre, Lecteur& lecteur){
		if(livre.getDispo()){
			//Creer un emprunt
			Emprunt empruntA(date::Date(1,1,2002), livre.getISBN(), lecteur.getIdent()); // la date d'emprunt est fausse
			livre.setDispo(false);
      _listeLivre.at(findListLivrePos(livre.getISBN())).setDispo(false);
			//TODO : vérifier que livre est dans la liste? Et que l'on emprunte pas plusieurs fois le même livre
			addEmprunt(empruntA);
			livre.addToList(lecteur.getIdent());
			lecteur.addToList(livre.getISBN());
			std::cout << lecteur.getPrenom() << " " << lecteur.getNom() << " a emprunté " << livre.getTitre() << std::endl;
		}else{
			std::cout << "Livre pas disponible" << std::endl;
		}

	}

	void Bibliotheque::restituer(std::string isbn, Lecteur& lecteur){ //un lecteur a seulement sa propre ident, donc il peut pas restituer pour un autre
		_listeEmprunt.at(searchEmprunt(isbn,lecteur.getIdent())).disable();
		//TODO : lecteur enleve le livre de sa liste
		searchLivre(isbn).setDispo(true);
    _listeLivre.at(findListLivrePos(isbn)).setDispo(true);


	}

	void Bibliotheque::searchLivre(Auteur& auteur) {
		std::vector<Livre> tab;
		for (int i = 0; i < _listeLivre.size(); i++){
			if (_listeLivre.at(i).getAuteurC() == auteur){
				tab.push_back(_listeLivre.at(i));
			}
		}

		std::string b;
		for (int i = 0; i < tab.size(); i++){
			b += toString(tab.at(i)) + "\n";
		}
		std::cout << b ; // TODO: faire fonctionner
	}

	int Bibliotheque::searchEmprunt(std::string isbn, std::string ident) const{
		for (int i = 0; i < _listeEmprunt.size(); i++){
			if ((_listeEmprunt.at(i).getISBN() == isbn) && (_listeEmprunt.at(i).getIdent() == ident)){
				//return _listeEmprunt.at(i);
        return i;
			}
		}
	}

	Livre Bibliotheque::searchLivre(std::string isbn) const{
		for (int i = 0; i < _listeLivre.size(); i++){
			if (_listeLivre.at(i).getISBN() == isbn){
				return _listeLivre.at(i);
			}
		}
	}

	void Bibliotheque::searchLivreDispo() const{
		std::vector<Livre> tab;
		for (int i = 0; i < _listeLivre.size(); i++){
			if (_listeLivre.at(i).getDispo()){
				tab.push_back(_listeLivre.at(i));
			}
		}

		std::string b;
		for (int i = 0; i < tab.size(); i++){
			b += toString(tab.at(i)) + "\n";
		}
    double pourcent = double(tab.size()) / double(_listeLivre.size()) * 100;
		std::cout << b << std::endl << "Pourcentage de livre non emprunter : " << pourcent << " %" << std::endl;
	}

  int Bibliotheque::findListLivrePos(std::string isbn) const{
    for (int i = 0; i < _listeLivre.size(); i++){
			if (_listeLivre.at(i).getISBN() == isbn){
				return i;
			}
		}
  }

  void Bibliotheque::searchLivreLecteur(std::string ident) const{
    std::vector<Livre> tab;
    for (int i = 0; i < _listeEmprunt.size(); i++){
			if ( _listeEmprunt.at(i).getState() &&_listeEmprunt.at(i).getIdent() == ident){
				tab.push_back(searchLivre(_listeEmprunt.at(i).getISBN()));
			}
		}
    
		std::string b;
		for (int i = 0; i < tab.size(); i++){
			b += toString(tab.at(i)) + "\n";
		}
		std::cout << b << std::endl;
  }

  int Bibliotheque::nombreLivreEmprunter(std::string ident) const{
    int a = 0;
    for (int i = 0; i < _listeEmprunt.size(); i++){
			if (_listeEmprunt.at(i).getIdent() == ident){
				a++;
			}
		}
    return a;
  }
  Lecteur Bibliotheque::searchLecteur(std::string ident) const{
    for (int i = 0; i < _listeLecteur.size(); i++){
      if(_listeLecteur.at(i).getIdent() == ident){
        return _listeLecteur.at(i);
      }
    }
  }

  void Bibliotheque::classementLecteur() const{
    std::vector<int> tab;
    std::vector<std::string> tab2;
    for (int i = 0; i < _listeLecteur.size(); i++){
		  tab.push_back(nombreLivreEmprunter(_listeLecteur.at(i).getIdent()));
      tab2.push_back(_listeLecteur.at(i).getIdent());
		}
    for (int i = 0; i < tab.size(); i++){
      for (int j = 0; j < tab.size()-1; j++){
        if(tab.at(j) < tab.at(j+1)){
          int a;
          std::string b;
          a = tab.at(j);
          tab.at(j) = tab.at(j+1);
          tab.at(j+1) = a;
          b = tab2.at(j);
          tab2.at(j) = tab2.at(j+1);
          tab2.at(j+1) = b;
        }
      }
    }
    for (int i = 0; i < tab2.size(); i++){
      searchLecteur(tab2.at(i)).afficherLecteur();
      std::cout << "Nombre de livre emprunter : " << tab.at(i) << std::endl;
    }
    
  }
}