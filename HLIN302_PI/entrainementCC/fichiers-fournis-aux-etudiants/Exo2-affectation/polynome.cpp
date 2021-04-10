#include "polynome.h"
#include <iostream>

using namespace std;

void Polynome::ajouterApresPos(Monome m,Monome* pos){
  if(pos!=NULL){
    Monome* tmp = pos->getSuiv();
    pos->setSuiv(new Monome(m.getNom(),m.getCoef(),m.getExp(),	\
			    m.getSuiv()));
    pos->getSuiv()->setSuiv(tmp);
  }else{
    tete = new Monome(m.getNom(),m.getCoef(),m.getExp(),tete);
  }
}

void Polynome::supprimerApresPos(Monome* pos){
  Monome* tmp = pos->getSuiv()->getSuiv();
  delete pos->getSuiv();
  pos->setSuiv(tmp);
}

Polynome::Polynome():tete(new Monome){}
Polynome::Polynome(Monome t):tete(new Monome(t.getNom(),t.getCoef(),t.getExp(),t.getSuiv())){}
Polynome::Polynome(Polynome &p){
  tete = new Monome(p.tete->getNom(),p.tete->getCoef(),p.tete->getExp(),p.tete->getSuiv());
  Monome* tmp = tete;
  while(p.tete->getSuiv()!=NULL){
    p.tete = p.tete->getSuiv();
    tete = tete->getSuiv();
    tete = new Monome(p.tete->getNom(),p.tete->getCoef(),p.tete->getExp(),p.tete->getSuiv());
  }
  tete = tmp;
}

void Polynome::suppr(){
  
  while(tete->getSuiv()!=NULL){
    supprimerApresPos(tete);
  }
  delete tete;
}

Polynome& Polynome::operator=(Polynome& p){
  if(&p!=this){

    suppr();

    Monome* tmp;
    tete = new Monome(p.tete->getNom(),p.tete->getCoef(),p.tete->getExp(),p.tete->getSuiv());
    tmp = tete;
    while(p.tete->getSuiv()!=NULL){
      p.tete = p.tete->getSuiv();
      tete = tete->getSuiv();
      tete = new Monome(p.tete->getNom(),p.tete->getCoef(),p.tete->getExp(),p.tete->getSuiv());
    }
    tete = tmp;
  }
  return *this;
}

void Polynome::ajouterDeb(Monome m){
  ajouterApresPos(m,NULL);
}
void Polynome::ajouterFin(Monome m){
  Monome* fin=tete;
  while(fin->getSuiv()!=NULL){
    fin = fin->getSuiv();
  }
  ajouterApresPos(m,fin);
}

void Polynome::ajouterPolynomeFin(Polynome p){
  Monome* tmp;
  tmp = p.tete;
  while(tmp!=NULL){
    ajouterFin(Monome(tmp->getNom(),tmp->getCoef(),tmp->getExp(),NULL));
    afficher();
    tmp = tmp->getSuiv();
  }
}

void Polynome::afficher() const{
  tete->affiche(false);
}

Polynome::~Polynome(){
  suppr();
}

///////////////////////////////////////////////////////////////////////////////////////

Polynome Polynome::substitue(const Polynome::cle_valeur &cl) const {
  Polynome P;
  P.ajouterFin(tete->substitue(cl.cle,cl.valeur));
  P.afficher();
}

/*
Polynome Polynome::substitue(const Polynome::cle_valeur *cl) const {
  // à compléter
}

#ifdef OP_AVEC_METHODE

// solution 1 opérateur '+'

#else

// solution 2 opérateur '+'

#endif
*/
