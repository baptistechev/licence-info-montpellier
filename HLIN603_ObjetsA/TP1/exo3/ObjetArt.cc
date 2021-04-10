#include "ObjetArt.h"

ObjetArt::ObjetArt() : Objet(), auteur("aut") {}

ObjetArt::ObjetArt(const string desc, const int ref, const string auteur) : Objet(desc,ref), auteur(auteur) {}

ObjetArt::~ObjetArt(){}

void ObjetArt::setAuteur(const string auteur){ this->auteur= auteur;}
string ObjetArt::getAuteur() const{ return auteur;}