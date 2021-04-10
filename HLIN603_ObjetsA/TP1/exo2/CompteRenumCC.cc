#include "CompteRenumCC.h"
#include<iostream>
using namespace std;

CompteRenumCC::CompteRenumCC() : CompteRenum(), frais(5){}

CompteRenumCC::~CompteRenumCC(){
    setSolde(getSolde()*(1+getTaux()) + frais);
}
void CompteRenumCC::deposer(const int montant, const int devise){
    CompteRenum::deposer(montant*(1+devise/100));
}