#include "cellule.h"
#include <iostream>

using namespace std;

#define N 3

void afficherGrille(Cellule grille[N][N]){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      grille[i][j].print();
    }
  }
}

void modifierGrille(Cellule grille[N][N]){
  cout << "Quel cellule voulez vous modifier ? (i,j) : " << endl;
  int i,j;
  cin >> i;
  cin >> j;
  grille[i][j].setVivante(!grille[i][j].getVivante());
  
}

int main(int argc, char** argv){

  Cellule grille[N][N];

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){

      grille[i][j].setVivante(((i+j)==1 || (i+j)==3) ? false : true);
      grille[i][j].setX(i);
      grille[i][j].setY(j);
     }
  }

  while(true){
      afficherGrille(grille);
      modifierGrille(grille);
    }
}

