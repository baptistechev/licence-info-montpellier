#include "triTas.h"
#include<iostream>
using namespace std;

#define pere(i) (i-1)/2
#define fg(i) 2*i+1
#define fd(i) 2*i+2

bool estRacine(size_t i){
  return i==0;
}

bool estFeuille(size_t i,size_t n){
  return (n+1)/2 >= i;
}

void entasser(TableauCell &T,size_t i,size_t n){
  
  if((fd(i)<n) && T.at(i).estAvant(T.at(fd(i)))){
    echanger(T.at(i),T.at(fd(i)));
    entasser(T,fd(i),n);
  }

  if((fg(i)<n) && T.at(i).estAvant(T.at(fg(i)))){
    echanger(T.at(i),T.at(fg(i)));
    entasser(T,fg(i),n);
  }
}

void initTas(TableauCell &T){
  for(size_t i=pere(T.size()-1);i != (size_t) -1;i--){
    entasser(T,i,T.size());
  }
}

void triTas(TableauCell &T){
  initTas(T);
  for(size_t i =T.size() -1;i != (size_t) -1;i--){
    echanger(T.at(0),T.at(i));
    entasser(T,0,i);    
  }  
}
