#include "population.h"
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

size_t Population::nb_voisins_vivants(size_t ci, size_t cj) const{
  int cpt=0;
  size_t imin,imax,jmin,jmax;
  imin = (ci==0)? ci : ci-1;
  imax = (ci==(N-1))? ci : ci+1;
  jmin = (cj==0)? cj : cj-1;
  jmax = (cj==(N-1))? cj : cj+1;

  for(size_t i=imin;i<=imax;i++){
    for(size_t j=jmin;j<=jmax;j++){
      if(pop[i][j].getVivante()) cpt++;
    }
  }
  return cpt - (pop[ci][cj].getVivante() ? 1 : 0);
}

void Population::updateColors(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      size_t voisin=nb_voisins_vivants(i,j);
      if(voisin!=3 && voisin!=2 && pop[i][j].getVivante())
	pop[i][j].doitMourir();
    }
  }
}

Population::Population(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      pop[i][j].setX(i);
      pop[i][j].setY(j);
      pop[i][j].setVivante(false);      
    }
  }
}

void Population::init(size_t n){

  srand(time(NULL));
  if(getCelluleVivantes()==0 && n <= N*N){
    size_t i,j;
    for(size_t k=0; k < n ; k++){
      do{
	i=rand()%N;
	j=rand()%N;
      }while((pop[i][j]).getVivante());
      pop[i][j].setVivante(true);
    }
    updateColors();
  }
}

size_t Population::nb_cellules(Cellule::Couleur color) const{
  size_t nb=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(CelluleEstDeLaCouleur(pop[i][j],color)){
	nb++;
      }
    }
  }
  return nb;
}

size_t Population::getCelluleVivantes() const{
  return N*N-getCelluleMortes();
}
size_t Population::getCelluleMortes() const{
  return nb_cellules(Cellule::NOIR);
}
size_t Population::getCelluleNees() const{
  return nb_cellules(Cellule::BLEU);
}
size_t Population::getCelluleVontMourrir() const{
  return nb_cellules(Cellule::ROUGE)+nb_cellules(Cellule::JAUNE);
}

Cellule Population::getCelluleCopie(size_t i, size_t j) const{
  checkG(i,j);
  return pop[i][j];
}
const Cellule& Population::getCellule(size_t i, size_t j) const{
  checkG(i,j);
  return pop[i][j];
}

void Population::print() const{
  for(int k = 0; k< N+2; k++){
    cout << "-";
  }
  cout<<endl;
  for(int i = 0; i<N ; i++){
    cout<<"|";
    for(int j = 0; j<N; j++){
      cout << Couleur2String(pop[i][j].getCouleur());
    }
    cout<<"|"<<endl;
  }
  for(int k = 0; k< N+2; k++){
    cout << "-";
  }
  cout << endl;
  std::cout << "Cellules vivantes : " << getCelluleVivantes() <<std::endl;
  std::cout << "Cellules mortes : " << getCelluleMortes() <<std::endl;

}

void Population::printCell(size_t i,size_t j) const{
  checkG(i,j);
  pop[i][j].print();
}

Population Population::next() const{
  Population POP(*this);
  for (size_t i = 0 ; i < N ; i++) {
    for (size_t j = 0 ; j < N ; j++) {
      size_t voisin=nb_voisins_vivants(i,j);
      (POP.pop[i][j]).setVivante(voisin ==3 || (voisin==2 && pop[i][j].getVivante()));
    }
  }
  POP.updateColors();
  return POP;
}




