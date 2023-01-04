#include <iostream>
#include "produit.h"

namespace mag{
Produit::Produit(std::string titre, std::string description, unsigned int quantite, double prix): _titre(titre), _description(description), _quantite(quantite), _prix(prix){

};
}