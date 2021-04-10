#include "Compte.h"
#include<iostream>
using namespace std;

Compte::Compte() : solde(0) {}

Compte::~Compte(){
    cout<<typeid(this).name()<<endl;
    cout << "Solde à rendre : " << solde << endl;
}

int Compte::getSolde()const{return solde;}
void Compte::setSolde(const int s){solde=s;}
void Compte::deposer(const int montant){solde+= montant;}