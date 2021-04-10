#include "population-vivante.h"
#include <exception>
#include <iostream>
#include <cstdlib>

using namespace std;

#define checkG(i,j)						\
  if(i<0 || j<0 || i>=N || j>=N){				\
    std::cout << "La cellule (" << i << "," << j		\
	      << ") n'est pas dans la grille" << std::endl;	\
    std::terminate();						\
  }

const Cellule* PopulationVivante::at(size_t i, size_t j) const{
  for(size_t k = 0; k < alive; k++){
    if(T[k].getX()==i && T[k].getY()==j){
      return T+k;
    }
  }
  return NULL;
}


Cellule* PopulationVivante::at(size_t i, size_t j){
  for(size_t k = 0; k < alive; k++){
    if(T[k].getX()==i && T[k].getY()==j){
      return T+k;
    }
  }
  return NULL;
}

size_t PopulationVivante::nb_voisins_vivants(size_t ci, size_t cj) const{
  int cpt=0;
  size_t imin,imax,jmin,jmax;
  imin = (ci==0)? ci : ci-1;
  imax = (ci==(N-1))? ci : ci+1;
  jmin = (cj==0)? cj : cj-1;
  jmax = (cj==(N-1))? cj : cj+1;

  for(size_t i=imin;i<=imax;i++){
    for(size_t j=jmin;j<=jmax;j++){
      if(at(i,j) != NULL) cpt++;
    }
  }
  return cpt - ((at(ci,cj) != NULL)? 1 : 0);
}

void PopulationVivante::updateColors(){
  for(size_t k = 0; k < alive; k++){
    size_t voisin=nb_voisins_vivants(T[k].getX(),T[k].getY());
    if(voisin!=3 && voisin!=2)
	T[k].doitMourir();
  }
}

PopulationVivante::PopulationVivante(size_t n):alive(0),N(n){
  if(N*N>NMAX){
    cout << "Probleme N trop grand" << endl;
  }  
}

void PopulationVivante::init(size_t n){

  srand(time(NULL));
  if(alive==0 && n <= N*N){
    size_t i,j;
    for(size_t k=0; k < n ; k++){
      do{
	i=rand()%N;
	j=rand()%N;
      }while(at(i,j)!=NULL);
      T[k]=Cellule(true,i,j);
      alive++;
    }
    updateColors();
  }
}

size_t PopulationVivante::nb_cellules(Cellule::Couleur color) const{
  size_t nb=0;
  for(size_t k=0; k < alive; k++){
      if(CelluleEstDeLaCouleur(T[k],color)){
	nb++;
    }
  }
  return nb;
}

size_t PopulationVivante::getCelluleVivantes() const{
  return alive;
}
size_t PopulationVivante::getCelluleMortes() const{
  return N*N-alive;
}
size_t PopulationVivante::getCelluleNees() const{
  return nb_cellules(Cellule::BLEU);
}
size_t PopulationVivante::getCelluleVontMourrir() const{
  return nb_cellules(Cellule::ROUGE)+nb_cellules(Cellule::JAUNE);
}

Cellule PopulationVivante::getCelluleCopie(size_t i, size_t j) const{
  checkG(i,j);
  const Cellule* ptr=at(i,j);
  if (ptr == NULL){
    return Cellule(false,i,j);
  }else{
    return *ptr;
  }
}
/*
const Cellule& PopulationVivante::getCellule(size_t i, size_t j) const{
  checkG(i,j);
  return pop[i][j];
}
*/
void PopulationVivante::print() const{
  for(size_t k = 0; k< N+2; k++){
    cout << "-";
  }
  cout<<endl;
  for(size_t i = 0; i<N ; i++){
    cout<<"|";
    for(size_t j = 0; j<N; j++){
      cout << Couleur2String(getCelluleCopie(i,j).getCouleur());
    }
    cout<<"|"<<endl;
  }
  for(size_t k = 0; k< N+2; k++){
    cout << "-";
  }
  cout << endl;
  std::cout << "Cellules vivantes : " << getCelluleVivantes() <<std::endl;
  std::cout << "Cellules mortes : " << getCelluleMortes() <<std::endl;

}

void PopulationVivante::printCell(size_t i,size_t j) const{
  checkG(i,j);
  getCelluleCopie(i,j).print();
}

void PopulationVivante::birth(size_t i, size_t j){
  if(alive+1<NMAX){
    Cellule* ptr = at(i,j);
    if(ptr == NULL){
      T[alive]=Cellule(true,i,j);
      alive++;
    }else{
      ptr->setVivante(true);
    }
  }else{
    cout << "Limite de capacité atteint !!" << endl;
    terminate();
  }
}

void PopulationVivante::kill(size_t i, size_t j){
  Cellule* ptr = at(i,j);
  if(ptr != NULL){
    for(size_t k = ptr-T; k < alive-1; k++){
      T[k]=T[k+1];
    }
    alive--;
  }
}

PopulationVivante PopulationVivante::next() const{
  PopulationVivante POP(*this);
  for (size_t i = 0 ; i < N ; i++) {
    for (size_t j = 0 ; j < N ; j++) {
      size_t voisin=nb_voisins_vivants(i,j);
      if((voisin ==3) || ((voisin==2) && (at(i,j)!=NULL))){
	POP.birth(i,j);
      }else{
	POP.kill(i,j);
      }
    }
  }
  POP.updateColors();
  return POP;
}




