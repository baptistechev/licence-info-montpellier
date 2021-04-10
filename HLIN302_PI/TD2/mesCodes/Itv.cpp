#include "Itv.h"
#include <iostream>

using namespace std;

Itv::Itv(){
  Itv(0.0,0.0);
}

Itv::Itv(float inf, float sup){
  if(inf<=sup){
    this->inf = inf;
    this->sup = sup;
  }else{
    cout << "Inversement des bornes car non conforme" << endl;
    this->inf = sup;
    this->sup = inf;
  }
}

float Itv::getInf() const{
  return this->inf;
}
float Itv::getSup() const{
  return this->sup;
}
void Itv::setInf(float inf){
  if (inf > this->sup){
    cout << "Les bornes sont non conforme donc inversés" << endl;
    this->inf = this->sup;
    this->sup = inf;
  }else{
    this->inf =inf;
  }
}
void Itv::setSup(float sup){
  if (sup < this->inf){
    this->sup = this->inf;
    this->inf = sup;
  }else{
    this->sup =sup;
  }
}
float Itv::longueur() const{
  return this->sup-this->inf;
}
bool Itv::appartient(float x) const{
  return (x>this->inf && x<this->sup);
}

bool Itv::estEgal(Itv I) const{
  return (inf == I.inf && sup == I.sup);
}
bool Itv::estInclusStrc(Itv I) const{
  return (inf >= I.inf && sup<=I.sup && (inf!=I.inf || sup!=I.sup));
}

bool Itv::estDisjoint(Itv I) const{
  return (inf > I.sup || I.inf > sup);
}
bool Itv::estAccole(Itv I) const{
  return (sup==I.inf || inf == I.sup);
}
bool Itv::estImbrique(Itv I) const{
  return (!estEgal(I) && !estInclusStrc(I) && !estDisjoint(I) && !estAccole(I));
}
void Itv::translater(float x){
  inf += x;
  sup += x;
}
