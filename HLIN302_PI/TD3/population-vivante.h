#include "cellule.h"

class PopulationVivante{

#define NMAX 1000

 private:
  Cellule T[NMAX];
  size_t N;
  size_t alive;
  const Cellule* at(size_t i, size_t j) const;
  Cellule* at(size_t i, size_t j); //ok
  size_t nb_cellules(Cellule::Couleur color) const;//ok
  size_t nb_voisins_vivants(size_t ci, size_t cj) const;//ok
  void updateColors();//ok
  
 public:
  PopulationVivante(size_t); //ok

  void init(size_t);//ok

  size_t getCelluleVivantes() const;//ok
  size_t getCelluleMortes() const;//ok
  size_t getCelluleNees() const;//ok
  size_t getCelluleVontMourrir() const;//ok

  Cellule getCelluleCopie(size_t i, size_t j) const;//ok
  //  const Cellule& getCellule(size_t i, size_t j) const;

  void print() const;//ok
  void printCell(size_t i,size_t j) const;//ok

  void birth(size_t i, size_t j);//ok
  void kill(size_t i, size_t j);//ok
  
  PopulationVivante next() const;//ok
};
