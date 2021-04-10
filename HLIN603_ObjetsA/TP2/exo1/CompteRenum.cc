#include "CompteRenum.h"
#include<iostream>
using namespace std;

CompteRenum::CompteRenum() : Compte(), taux(0.1){}

CompteRenum::~CompteRenum(){
    setSolde(getSolde()*(1+taux));
    cout<<typeid(this).name()<<endl;

}
void CompteRenum::deposer(const int montant){
    Compte::deposer(montant*(1+0.01));
}

float CompteRenum::getTaux()const{return taux;}