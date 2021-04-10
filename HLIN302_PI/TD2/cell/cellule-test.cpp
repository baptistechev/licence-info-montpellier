#include "Cellule.h"
#include <iostream>

using namespace std;

void test_cell(Cellule c){
  cout << "La cellule est positionner à l'emplacement : ("<< c.getX() << "x" << c.getY() << ") et est : " << ((c.getEstVivante())? "vivante," : "morte,")<< " sa couleur est : " << c.afficherColor() << endl;
}

bool estCelluleColor(Cellule c,Cellule::Color color){
  return (c.getColor()==color);
}

#define printVoisines(c1,c2)							\
  cout<< "La cellule " << #c1 <<" est " << ((c1.estVoisine(c2))? "voisine" : "non voisine") << " de " << #c2 << endl

#define printCelluleColor(c, color) \
  cout << "La cellule "<< #c <<" est de couleur " << #color<< " : " << ((estCelluleColor(c,color))? "vrai" : "faux") << endl;

int main(int argc, char** argv){
  
  Cellule c1(true, 1, 2, Cellule::GREEN), c2;
  c2.setEstVivante(!c2.getEstVivante());
  c2.setX(c1.getX());
  c2.setY(c1.getX() + c1.getY());
  test_cell(c1); test_cell(c2);
  printVoisines(c1, c2); printVoisines(c2, c1);
  printCelluleColor(c1,Cellule::GREEN);

  
}
