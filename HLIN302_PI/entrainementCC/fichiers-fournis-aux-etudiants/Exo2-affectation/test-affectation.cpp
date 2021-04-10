#include <iostream>
#include "polynome.h"
#include "monome.h"

using namespace std;

int main(int argc, char **argv) {
  /*
  Polynome p;
  Monome m("x",3,2,NULL);
  m.affiche(true);
  Monome m1 = m.substitue("x",3);
  Monome m2 = m.substitue("y",3);
  m1.affiche(true);
  m2.affiche(true);
  */
  
  Polynome P(Monome("y",3,3,NULL));  
  P.ajouterFin(Monome("x",3.4,2,NULL));
  P.ajouterDeb(Monome("x",2.8,4,NULL));
  P.afficher();
  
  Polynome::cle_valeur cl[] = {
    {"x", -1.2}, // La variable "x" est associée à la valeur -1.2
    {"y", 2}, // La variable "z" est associée à la valeur 2
    {NULL, 0} // Permet de parcourir le tableau sans connaître sa taille
  };

  P.substitue(cl[0]);
  P.afficher();

  /*
  Polynome ap = p % cl; // Le polynôme ap est le résultat des
                        // substitutions dans le polynôme p.

  cout << "polynome p = "; p.affiche(); cout << endl;
  cout << "polynome p % { {\"x\", 1.2}, {\"z\", 4} } } = "; ap.affiche(); cout << endl;

  cl[1].cle = "y"; // Finalement ce n'est plus "z" mais "y" qui est
                   // associée à la valeur 2.

  ap = ap % cl; // Le polynôme ap est le résultat des substitutions dans
                // lui-même.

  cout << "polynome ap % { {\"x\", 1.2}, {\"y\", 2} } } = "; ap.affiche(); cout << endl;
  */
  return 0;
}
