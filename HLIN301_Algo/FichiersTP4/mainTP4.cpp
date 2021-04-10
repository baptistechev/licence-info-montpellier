#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
//#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
#include "fichierTP4.h"
using namespace std;


/*****************************************************************************/
/*                                                                           */
/*                              main                                         */
/*                                                                           */
/*****************************************************************************/
int main(int argc, char *argv[]){
  int q,i;
  ArbreBin A,B,C;
  ostringstream stre;
  ListeSC L;
  string  chaine;
  A=creerArbreBin(8,
		  creerArbreBin(7,
				creerArbreBin(4,NULL,NULL),
				creerArbreBin(9,NULL,NULL)),
		  creerArbreBin(3,NULL,NULL));

  B=creerArbreBin(8,
		  creerArbreBin(2,
				creerArbreBin(4,NULL,NULL),
				creerArbreBin(9,
					      NULL,
					      creerArbreBin(1,
							    NULL,
							    creerArbreBin(7,
									  creerArbreBin(11,NULL,NULL),
									  creerArbreBin(5, 
											NULL,
											NULL))))),
		  creerArbreBin(3,
				creerArbreBin(12,
					      creerArbreBin(6,NULL,NULL),
					      NULL),
				creerArbreBin(9,NULL,NULL)));
  C=NULL;
  C= creerArbreBin(1,C,C);
  cout << "Numero de la question traitee (1/2/3/4/5/6/7) ? ";
  cin >> q;
  switch (q){
  case 1 :
    dessinerAB(A,"arbre.dot","Arbre Bin");
    cout << "Somme des noeuds de l'arbre :"<< sommeNoeuds(A) << endl;
    cout << "Profondeur minimum des feuilles de l'arbre : " << profMinFeuille(A) << endl;
    system("dotty arbre.dot");
    break;
  case 2 :
    dessinerAB(A,"arbre.dot","Arbre Bin");    
    L=parcoursInfixe(A);
    cout << "Liste des noeuds de l'arbre en ordre infixe : ";
    afficherLSC(L);
    system("dotty arbre.dot");
    break;
  case 3 :
    dessinerAB(B,"arbre.dot","Arbre Bin");
    system("dotty arbre.dot&");
    effeuiller(B);
    dessinerAB(B,"arbre2.dot","Arbre Bin effeuille");
    system("dotty arbre2.dot");
    break;
  case 4 :
    dessinerAB(B,"arbre.dot","Arbre Bin");
    system("dotty arbre.dot&");
    cout << " Donner une profondeur (entier positif) :";
    cin >> i;
    tailler(B,i);
    stre << i;
    chaine = stre.str();
    chaine = "Arbre Bin taille a la profondeur " + chaine;
    dessinerAB(B,"arbre2.dot",chaine);
    system("dotty arbre2.dot&");
    break;
  case 5 :
    cout << " Donner un entier positif :";
    cin >> i;
    stre << i;
    chaine = "Arbre Bin  " + stre.str();
    dessinerAB(genereAB(i),"arbre.dot", "Arbre Bin  " + stre.str());
    system("dotty arbre.dot&");
    break;
  case 6 :
    dessinerAB(B,"arbre.dot","Arbre Bin");
    system("dotty arbre.dot&");
    tronconner(B);
    dessinerAB(B,"arbre2.dot","Arbre tronconne");
    system("dotty arbre2.dot&");
    break;
  case 7 :
    A=genereAB(7);
    chaine= estParfait(A) ? "Arbre parfait" : "Arbre non parfait";
    dessinerAB(A,"arbre.dot",chaine);
    system("dotty arbre.dot");
    cout << chaine << endl;
    
    B=genereAB(8);
    chaine= estParfait(B) ? "Arbre parfait" : "Arbre non parfait";
    dessinerAB(B,"arbre2.dot",chaine);
    system("dotty arbre2.dot&");
    cout << chaine << endl;
    
    break;
  }
  return 0;
}
