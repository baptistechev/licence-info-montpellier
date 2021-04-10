#include "triTas.h"
#include <iostream>
#include <ctime>

#define tailleT 5000
#define trieAffichage \
  cout << (estTrieTab(T)? "Trie" : "Non trie") << endl

using namespace std;

int rechercheDic(Cellule c,TableauCell T){

  int deb=0,fin=T.size()-1,mil;
  while(deb<fin){
    mil = (deb+fin)/2;
    if(T.at(mil).estAvant(c)){
      deb=mil+1;
    }else if(T.at(mil).estApres(c)){
      fin = mil-1;
    }else{
      return mil;
    }
  }
  return -1;
}

bool estTrieTab(TableauCell T){
  for(size_t i=0;i<T.size()-1;i++){
    if(T.at(i).estApres(T.at(i+1))){
      return false;
    }
  }
  return true;
}

void triBulle(TableauCell &T){
  bool estTrie = false;
  size_t n = T.size()-1;
  Cellule sav;
  while(!estTrie && n){
    n--;
    estTrie = true;
    for(size_t i=0;i<=n;i++){
      if(T.at(i).estApres(T.at(i+1))){
	sav=T.at(i);
	T.at(i) = T.at(i+1);
	T.at(i+1) = sav;
	estTrie = false;
      }
    }
  }
}

void triRapideAux(TableauCell &T,int deb, int fin){
  if(deb>=fin) return;
  int d = deb, f = fin, piv = (deb+fin)/2;
  Cellule sav;
  while(d<f){
    while((d<piv) && T.at(d).estAvantOuEquivalente(T.at(piv))){
      d++;
    }
    while((f>piv) && T.at(f).estApresOuEquivalente(T.at(piv))){
      f--;
    }
    sav = T.at(d);
    T.at(d) = T.at(f);
    T.at(f) = sav;
    
    if(piv == d){
      piv = f;
    }else if(piv == f){
      piv =d;
    }
  }
  triRapideAux(T,deb,piv-1);
  triRapideAux(T,piv+1,fin);
}

void triRapide(TableauCell &T){
  triRapideAux(T,0,T.size()-1);
}

int main(int argc,char** argv){

  TableauCell T(tailleT);
  for(int i =0;i<tailleT;i++){
    T.at(i)=Cellule(true,tailleT-1-i,0);
  }
  //  T.write(std::cout);
  //trieAffichage;
  cout<<endl;

  TableauCell sav=T;

  
  time_t start = std::time(NULL);
  trieAffichage;
  triBulle(T);
  cout << "Trie Bulle tps : " << difftime(std::time(NULL), start) << endl;
  trieAffichage;
  

  T=sav;
  start = std::time(NULL);
  trieAffichage;
  triRapide(T);
  cout << "Tri Rapide tps : " << difftime(std::time(NULL), start) << endl;
  trieAffichage;

  
  T=sav;
  start = std::time(NULL);
  trieAffichage;
  triTas(T);
  cout << "Tri Tas tps : " << difftime(std::time(NULL), start) << endl;
  trieAffichage;
  
}

