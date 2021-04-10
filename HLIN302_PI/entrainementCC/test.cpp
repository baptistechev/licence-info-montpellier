#include "polynome.h"
#include <iostream>

using namespace std;

int main(int argc,char** argv){

  /*
  Monome M1("x",3.4,2,NULL);
  Monome M2("y",2.8,4,&M1);
  Monome M3("z",3,3,NULL);
  */

  Polynome P(Monome("z",3,3,NULL));
  Polynome P2(P);
  P.afficher();
  P2.afficher();
  
  P.ajouterFin(Monome("x",3.4,2,NULL));
  P.ajouterDeb(Monome("y",2.8,4,NULL));
  P.afficher();
  P2.afficher();

  P2.ajouterPolynomeFin(P);
  P.afficher();
  P2.afficher();

  /*  cout << M2.getCoef() << M2.getNom() << "^" << M2.getExp() << " + " \
       << M2.getSuiv().getCoef() << M2.getSuiv().getNom() << "^" << M2.getSuiv().getExp() << endl;

  M2.setSuiv(NULL);

    cout << M2.getCoef() << M2.getNom() << "^" << M2.getExp() << " + " \
       << M2.getSuiv().getCoef() << M2.getSuiv().getNom() << "^" << M2.getSuiv().getExp() << endl;
  */


 
  return 0;
}
