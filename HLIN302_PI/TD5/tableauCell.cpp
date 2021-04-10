#include "tableauCell.h"
#include <iostream>

void TableauCell::extend(){
  if(n<N) return;
  N*=2;
  Cellule* tab = new Cellule[N];
  for(size_t i=0;i<n;i++){
    tab[i]=T[i];
  }
  delete[] T;
  T = tab;
}

TableauCell::TableauCell():T(NULL),n(0),N(1){}

TableauCell::TableauCell(size_t n):T(new Cellule[n]),n(n),N(n){}

TableauCell::TableauCell(const TableauCell& t):T(new Cellule[t.n]),n(t.n),N(t.n){
  for(size_t i=0;i<n;i++){
    T[i]=t.T[i];
  }
}

TableauCell& TableauCell::operator=(const TableauCell& t){
  if(this!=&t){
    delete[] T;
    new Cellule[t.n];
    n=t.n;
    N=n;
    for(size_t i=0;i<n;i++){
      T[i]=t.T[i];
    }
  }
  return *this;
}

size_t TableauCell::size() const{return n;}

Cellule& TableauCell::at(size_t i){
  return T[i];
}

const Cellule& TableauCell::at(size_t i)const{
  return T[i];
}

void TableauCell::pushback(Cellule x){
  extend();
  T[n]=x;
  n++;
}

void TableauCell::erase(size_t id){
  if(id<n){
    for(size_t i=id;i<n-1;i++){
      T[i]=T[i+1];
    }
    n--;
  }
}

TableauCell::~TableauCell(){delete[] T;}

void read_cell(std::istream& is, Cellule& C){
  size_t x,y,b;
  is>>x>>y>>b;
  C.setX(x);
  C.setY(y);
  C.setVivante(b);
}

void write_cell(std::ostream& os, const Cellule& C){
  os<<C.getX()<<" "<<C.getY()<<" "<<C.getVivante()<<std::endl;
}

void TableauCell::read(std::istream& is){
  for(size_t i=0;i<n;i++) {read_cell(is,T[i]);}
}

void TableauCell::write(std::ostream& os)const{
  for(size_t i=0;i<n;i++) {write_cell(os,T[i]);}
}

int TableauCell::find(const Cellule& C) const{
  for(size_t i=0;i<n;i++){
    if(T[i].getX()==C.getX() && T[i].getY()==C.getY() && T[i].getVivante()==C.getVivante()){
      return i;
    }
  }
  return -1;
}

