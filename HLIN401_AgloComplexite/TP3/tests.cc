#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "SetCover.h"
#include "AffichageMaisons.h"

void GenererMaisons(int n, int coordMaisons[][2])
{
  for(int i=0;i<n;i++)
  {
    coordMaisons[i][0]=10+rand()%593;
    coordMaisons[i][1]=10+rand()%773;

  }
}

int main(int argc, char** argv)
{
  int n;
  if (argc < 2)
  {
    cout << "Entrer le nombre de maisons: ";
    cin >> n;
  }
  else
  {
    n = atoi(argv[1]);
  }
  
  srand(time(NULL));
  
  if (n == 0) return 0;

  int coordMaisons[n][2]; // coordonnées des maisons dans le plan
  bool emetteurs[n];       // numéro des maisons que l'on choisit pour placer des émetteurs
  
  GenererMaisons(n, coordMaisons);
  AffichageMaisons(n, coordMaisons, "Maisons");
  cout << "Fichier Maisons.ps mis à jour" << endl;

  for (int i=0; i < n; i++) emetteurs[i] = false;
  int nbEmetteurs = ChoixEmetteurs(n, coordMaisons, emetteurs);
  AffichageMaisonsEmetteurs(n, coordMaisons, emetteurs, "Emetteurs");
  cout << "Nombre d'émetteurs placés : "<< nbEmetteurs; 
  cout << "; fichier Emetteurs.ps mis à jour" << endl;

  bool emetteursOpt[n];
  for (int i=0; i < n; i++) emetteursOpt[i] = false;
  int nbEmetteursOpt = ChoixEmetteursOpt(n, coordMaisons, emetteursOpt);
  AffichageMaisonsEmetteurs(n, coordMaisons, emetteursOpt, "EmetteursOpt");
  cout << "Nombre d'émetteurs optimal : " << nbEmetteursOpt;
  cout << "; fichier EmetteursOpt.ps mis à jour" << endl;
  
  return 0;
}

