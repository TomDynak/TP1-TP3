#include <iostream>
#include <string>
#include <vector>
#include "date.h"
#include "livre.h"
#include "auteur.h"
#include "emprunt.h"
#include "lecteur.h"
#include "bibliotheque.h"


int main(){
    //Création des instances
    bibli::Bibliotheque Municipale;
    bibli::Auteur AuteurA("0000000a","Gimli","Dimitri", date::Date(1,10,1963));
    bibli::Auteur AuteurB("00000001","Toukan","Pedro", date::Date(22,6,1989));
    bibli::Auteur AuteurC("00000002","Anry","Videl", date::Date(30,4,2000));
    bibli::Auteur AuteurD("00000003","Robin","Becken", date::Date(25,12,1943));
    //Créativité mis a rude epreuve, mais ça en valait la peine
    bibli::Livre LivreA("Raz de maréchaussée",AuteurA,"Thriller, Documentaire", date::Date(20,2,1999), "000000000a", true);
    bibli::Livre LivreB("L'allemand un language tout simple",AuteurB,"Fantasy", date::Date(17,12,2010), "0000000001", true);
    bibli::Livre LivreC("Champion-pignon",AuteurA,"Roman Detective", date::Date(12,3,1982), "0000000002", true);
    bibli::Livre LivreD("Feur",AuteurC,"Thriller", date::Date(1,8,2018), "0000000003", true);
    bibli::Livre LivreE("Cauchemar au pique-nique",AuteurB,"Documentaire", date::Date(2,10,2005), "0000000004", true);
    bibli::Livre LivreF("L'enfer est dans les pré",AuteurB,"Science-ficiton", date::Date(27,6,2012), "0000000005", true);
    bibli::Livre LivreG("Memoire de mes deboires",AuteurD,"Roman", date::Date(5,5,1974), "0000000006", true);
    bibli::Livre LivreH("Transformé de bourré",AuteurB,"Roman", date::Date(14,9,2008), "0000000007", true);
    bibli::Livre LivreI("Pifomètre",AuteurC,"Thriller", date::Date(30,6,2021), "0000000008", true);

    bibli::Lecteur LecteurA("0000000a","Dubois","Angela");
    bibli::Lecteur LecteurB("00000001","Braise","Pierre");
    //Ajout des instances crée dans la Bibliothèque
    Municipale.addAuteur(AuteurA);
    Municipale.addAuteur(AuteurB);
    Municipale.addAuteur(AuteurC);
    Municipale.addAuteur(AuteurD);

    Municipale.addLivre(LivreA);
    Municipale.addLivre(LivreB);
    Municipale.addLivre(LivreC);
    Municipale.addLivre(LivreD);
    Municipale.addLivre(LivreE);
    Municipale.addLivre(LivreF);
    Municipale.addLivre(LivreG);
    Municipale.addLivre(LivreH);
    Municipale.addLivre(LivreI);

    Municipale.addLecteur(LecteurA);
    Municipale.addLecteur(LecteurB);
    //Affichage
    std::cout << AuteurA << AuteurB << AuteurC << AuteurD << LecteurA << LecteurB << std::endl;
    std::cout << LivreA << LivreB << LivreC << LivreD << LivreE << LivreF << LivreG << LivreH << LivreI << std::endl;
    std::cout << "------------------------Emprunt-----------------------" << std::endl;
    //On test l'emprunt de livre
    Municipale.emprunter(LivreE,LecteurA);
    Municipale.emprunter(LivreC,LecteurA);
    //On ne peut pas emprunter 2 fois le même livre
    Municipale.emprunter(LivreE,LecteurB);
    Municipale.emprunter(LivreH,LecteurB);
    std::cout << "-----------Recherche de livre d'un auteur-------------" << std::endl;
    Municipale.searchLivre(AuteurB);
    std::cout << "------------Recherche de livre disponible-------------" << std::endl;
    Municipale.searchLivreDispo();
    std::cout << "------------Recherche de livre d'un lecteur-----------" << std::endl;
    Municipale.searchLivreLecteur(LecteurA.getIdent());
    std::cout << "------------------Classement--------------------------" << std::endl;
    std::cout << "Classement des lecteurs" << std::endl;
    Municipale.classementLecteur();
    std::cout << "------------------Test restitution--------------------" << std::endl;
    Municipale.restituer(LivreE.getISBN(), LecteurA);
    Municipale.searchLivreLecteur(LecteurA.getIdent());
    return 0;
}