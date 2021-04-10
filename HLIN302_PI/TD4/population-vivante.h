#include "cellule.h"

class PopulationVivante{

#define NMAX 10000

 private:
  Cellule T[NMAX];
  size_t N;
  size_t alive;
  float proba;
  
  const Cellule* at(size_t i, size_t j) const;
  Cellule* at(size_t i, size_t j); 
  size_t nb_cellules(Cellule::Couleur color) const;
  size_t nb_voisins_vivants(size_t ci, size_t cj) const;
  void updateColors();
  
 public:
  PopulationVivante(size_t n, float prob); 

  //getters
  
  size_t getCelluleVivantes() const;
  size_t getCelluleMortes() const;
  size_t getCelluleNees() const;
  size_t getCelluleVontMourrir() const;
  float getProba() const;
  size_t getDim() const;
  
  Cellule getCelluleCopie(size_t i, size_t j) const;

  void print() const;
  void printCell(size_t i,size_t j) const;

  //setters
  
  void birth(size_t i, size_t j);
  void kill(size_t i, size_t j);
  void setProba(float proba);
  void setDim(size_t dim);

  void reset();
  
  PopulationVivante next() const;
};
