#include "monome.h"
#include <iostream>

using namespace std;

//Constructeur
Monome::Monome():nom(""),coef(0),exp(0),suiv(NULL){}
Monome::Monome(std::string name,float c,int e,Monome* m):nom(name),coef(c),exp(e),suiv(m){}

//Setters
void Monome::setNom(std::string n){nom=n;}
void Monome::setCoef(float c){coef=c;}
void Monome::setExp(int e){exp=e;}
void Monome::setSuiv(Monome* s){suiv=s;}

//Getters
std::string Monome::getNom() const{return nom;}
float Monome::getCoef() const{return coef;}
int  Monome::getExp() const{return exp;}
Monome* Monome::getSuiv() const{return suiv;}

//Methodes
void Monome::affiche(bool courant) const{
  if(exp == 1){
    cout << coef << nom;
  }else if(nom=="" || exp==0){
    cout << coef;
  }else{
    cout << coef << nom << "^" << exp;
  }
  
  if(!courant){
    if(suiv != NULL){
      cout<< " + ";
      suiv->affiche(false);
    }else{
      cout << endl;
    }
  }else{
    cout << endl;
  }
}

