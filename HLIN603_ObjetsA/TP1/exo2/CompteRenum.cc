#include "CompteRenum.h"
#include<iostream>
using namespace std;

CompteRenum::CompteRenum() : Compte(), taux(0.1){}

CompteRenum::~CompteRenum(){
    setSolde(getSolde()*(1+taux));
}
void CompteRenum::deposer(const int montant){Compte::deposer(montant*(1+taux));}

float CompteRenum::getTaux()const{return taux;}