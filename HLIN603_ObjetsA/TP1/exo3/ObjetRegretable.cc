#include "ObjetRegretable.h"

ObjetRegretable::ObjetRegretable() : Objet(), donateur("don"), annee(2000) {}

ObjetRegretable::ObjetRegretable(const string desc, const int ref, const string donateur, const int annee) : Objet(desc, ref), donateur(donateur), annee(annee) {}

ObjetRegretable::~ObjetRegretable(){}

void ObjetRegretable::setDonateur(const string donateur){ this->donateur= donateur;}
void ObjetRegretable::setAnnee(const int annee){ this->annee= annee;}
string ObjetRegretable::getDonateur() const{ return donateur;}
int ObjetRegretable::getAnnee() const{ return annee;}