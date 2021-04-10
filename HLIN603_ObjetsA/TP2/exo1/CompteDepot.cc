#include "CompteDepot.h"
#include<iostream>
using namespace std;

CompteDepot::CompteDepot() : Compte(), frais(100){}

CompteDepot::~CompteDepot(){
    setSolde(getSolde()-frais);
    cout<<typeid(this).name()<<endl;
}
void CompteDepot::deposer(const int montant){
    Compte::deposer( ((montant>=1000) ? montant+10 : montant ) - 1);
}