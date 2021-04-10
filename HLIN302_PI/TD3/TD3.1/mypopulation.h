#include "cellule.h"

#define N 3

Class Population{

 private:
  Cellule pop[N][N];
  size_t nb_cellule(Cellule::Couleur couleur) const;

 public:
  Population();
  Population(size_t k);
  Cellule getCellule(size_t x, size_t y) const;
  size_t nbVivantes() const;
  size_t nbMortes() const;
  size_t nbNaissante() const;
  size_t nbMourante() const;


  
};
