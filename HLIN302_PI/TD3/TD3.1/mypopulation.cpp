#include "cellule.h"
#include <iostream>

int main(int argc, char** argv){

  Cellule pop[3][3];

  for(size_t i=0;i<3;++i){
    for(size_t j=0; j<3; ++j){
      char rep;
      pop[i][j].setX(i);
      pop[i][j].setY(j);
      std::cout<< "La cellule (" << i << "x" << j << ") doit-elle vivre (o/N) ?" << std::endl;
      std::cin >> rep;
      pop[i][j].setVivante((rep == 'o') || (rep == 'O' ));
    }
  }
  

  return 0;
}
