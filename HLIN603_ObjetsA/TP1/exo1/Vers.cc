#include<iostream>
#include<string>
using namespace std;
#include"Vers.h"

Vers::Vers(){}

Vers::Vers(string sm){suiteMots=sm;}

Vers::Vers(string sm, string r){suiteMots=sm;rime=r;}

Vers::~Vers(){cout <<"destructeur vers" <<endl;}

string Vers::getSuiteMots()const
    {return suiteMots;}

void Vers::setSuiteMots(string sm)
    {suiteMots=sm;}

string Vers::getRime()const
    {return rime;}

void Vers::setRime(string r)
    {rime=r;}

void Vers::saisie(istream& is)
    {cout <<"vers puis rime" <<endl;is>>suiteMots>>rime;}

void Vers::affiche(ostream& os)const
    {os<<"<<"<<suiteMots<<">>";}
