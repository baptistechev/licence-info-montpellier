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

size_t PopulationVivante::nb_voisins_vivants(size_t ci, size_t cj) const{
  int cpt=0;
  size_t imin,imax,jmin,jmax;
  imin = (ci==0)? ci : ci-1;
  imax = (ci==(N-1))? ci : ci+1;
  jmin = (cj==0)? cj : cj-1;
  jmax = (cj==(N-1))? cj : cj+1;

  for(size_t i=imin;i<=imax;i++){
    for(size_t j=jmin;j<=jmax;j++){
      if(T.find(Cellule(true,i,j))!=-1) cpt++;
    }
  }
  return cpt - ((T.find(Cellule(true,ci,cj))!=-1)? 1 : 0);
}

void PopulationVivante::updateColors(){
  for(size_t k = 0; k < T.size(); k++){
    size_t voisin=nb_voisins_vivants(T.at(k).getX(),T.at(k).getY());
    if(voisin!=3 && voisin!=2)
      T.at(k).doitMourir();
  }
}
//////////////////////////////////////
///////////CONSTRUCTEURS//////////////
//////////////////////////////////////

PopulationVivante::PopulationVivante(size_t n,float prob):T(),N(n),proba(prob){
  reset();  
}

//////////////////////////////////////

size_t PopulationVivante::nb_cellules(Cellule::Couleur color) const{
  size_t nb=0;
  for(size_t k=0; k < T.size(); k++){
    if(CelluleEstDeLaCouleur(T.at(k),color)){
	nb++;
    }
  }
  return nb;
}

//////////////////////////////////////////
//////////// GETTERS//////////////////////
//////////////////////////////////////////

size_t PopulationVivante::getCelluleVivantes() const{
  return T.size();
}
size_t PopulationVivante::getCelluleMortes() const{
  return N*N-T.size();
}
size_t PopulationVivante::getCelluleNees() const{
  return nb_cellules(Cellule::BLEU);
}
size_t PopulationVivante::getCelluleVontMourrir() const{
  return nb_cellules(Cellule::ROUGE)+nb_cellules(Cellule::JAUNE);
}
float PopulationVivante::getProba() const{
  return proba;
}
size_t PopulationVivante::getDim() const{
  return N;
}

//////////////////////////////////////////////////

Cellule PopulationVivante::getCelluleCopie(size_t i, size_t j) const{
  checkG(i,j);
  int id = T.find(Cellule(true,i,j));
  if (id == -1){
    return Cellule(false,i,j);
  }else{
    return T.at(id);
  }
}

void PopulationVivante::print() const{
  for(size_t k = 0; k< N+2; k++){
    cout << "-";
  }
  cout<<endl;
  for(size_t i = 0; i<N ; i++){
    cout<<"|";
    for(size_t j = 0; j<N; j++){
      int id = T.find(Cellule(true,i,j));
      if(id != -1){
	cout<<Couleur2String(T.at(id).getCouleur());
      }else{
	cout<<Couleur2String(Cellule::NOIR);
      }
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

void PopulationVivante::print(std::ostream& os)const{
  os<<N<<" "<<T.size()<<std::endl;
  T.write(os);  
}

void PopulationVivante::printCell(size_t i,size_t j) const{
  checkG(i,j);
  getCelluleCopie(i,j).print();
}

//////////////////////////////////////////
///////////////SETTERS////////////////////
//////////////////////////////////////////

void PopulationVivante::birth(size_t i, size_t j){
  int id = T.find(Cellule(true,i,j));
  if(id == -1){
    T.pushback(Cellule(true,i,j));
  }else{
    T.at(id).setVivante(true);
  }
}

void PopulationVivante::kill(size_t i, size_t j){
  T.erase(T.find(Cellule(true,i,j)));
}

void PopulationVivante::setProba(float proba){
  this->proba = proba; reset();
}
void PopulationVivante::setDim(size_t dim){
  N=dim; reset();
}

//////////////////////////////////////////////////

void PopulationVivante::reset() {
  srand(time(NULL));
  T = TableauCell();
  if (proba < 0.5) {
    for (size_t x = 0 ; x < N * N * proba ; x++) {
      size_t i,j;
      Cellule c(true, i, j);
      do {
        i = rand() % N;
        j = rand() % N;
      } while (T.find(c) != -1);
      T.pushback(c);
    }
  } else {
    for (size_t i = 0; i < N; i++) {
      for (size_t j = 0; j < N; j++) {
        if ((rand() % 10000) / 10000. <= proba) {
          T.pushback(Cellule(true, i, j));
        }
      }
    }
  }
  updateColors();
}

PopulationVivante PopulationVivante::next() const{
  PopulationVivante POP(*this);
  for (size_t i = 0 ; i < N ; i++) {
    for (size_t j = 0 ; j < N ; j++) {
      size_t voisin=nb_voisins_vivants(i,j);
      if((voisin ==3) || ((voisin==2) && (T.find(Cellule(true,i,j))!=-1))){
	POP.birth(i,j);
      }else{
	POP.kill(i,j);
      }
    }
  }
  POP.updateColors();
  return POP;
}




