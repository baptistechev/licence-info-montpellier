#include "tableauInt.h"
#include <iostream>

void TableauInt::extend(){
  if(n<N) return;
  N*=2;
  int* tab = new int[N];
  for(size_t i=0;i<n;i++){
    tab[i]=T[i];
  }
  delete[] T;
  T = tab;
}

TableauInt::TableauInt(size_t n):T(new int[n]),n(n),N(n){}

TableauInt::TableauInt(const TableauInt& t):T(new int[t.n]),n(t.n),N(t.n){
  for(size_t i=0;i<n;i++){
    T[i]=t.T[i];
  }
}

TableauInt& TableauInt::operator=(const TableauInt& t){
  if(this!=&t){
    delete[] T;
    new int[t.n];
    n=t.n;
    N=n;
    for(size_t i=0;i<n;i++){
      T[i]=t.T[i];
    }
  }
  return *this;
}

size_t TableauInt::size() const{return n;}

int& TableauInt::at(size_t i){
  return T[i];
}

const int& TableauInt::at(size_t i)const{
  return T[i];
}

void TableauInt::pushback(int x){
  extend();
  T[n]=x;
  n++;
}

TableauInt::~TableauInt(){delete[] T;}



void write(std::ostream& os, const TableauInt& t){
  for(size_t i=0;i<t.size();i++){
    os<<t.at(i)<<" ";
  }
  os<<std::endl;
}
