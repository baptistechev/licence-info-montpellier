#include "cellule.h"

class Population{

#define N 30

 private:
  Cellule pop[N][N];
  size_t nb_cellules(Cellule::Couleur color) const;
  size_t nb_voisins_vivants(size_t ci, size_t cj) const;
  void updateColors();
  
 public:
  Population();

  void init(size_t);

  size_t getCelluleVivantes() const;
  size_t getCelluleMortes() const;
  size_t getCelluleNees() const;
  size_t getCelluleVontMourrir() const;

  Cellule getCelluleCopie(size_t i, size_t j) const;
  const Cellule& getCellule(size_t i, size_t j) const;

  void print() const;
  void printCell(size_t i,size_t j) const;

  Population next() const;
};
