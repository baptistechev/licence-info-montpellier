#include <iostream>
#include "Itv.h"

using namespace std;

int main(int argc, char** argv){

  Itv I1,I2(6,12);

  cout << "Test de getInf,getSup" << endl;
  cout << "[" << I1.getInf() << "," << I1.getSup() << "]" << endl;

  cout << "Test de setInf,setSup" << endl;
  I1.setInf(3);
  I1.setSup(8);
  cout << "[" << I1.getInf() << "," << I1.getSup() << "]" << endl;

  cout << "Test de longueur" << endl;
  cout << "La longueur de l'intervalle est : " << I1.longueur() << endl;

  cout << "Test de appartient" << endl;
  cout << "Le flotant 1,2 appartient à I1 : " << I1.appartient(1.2) << endl;

  cout << "Test de estEgal" << endl;
  cout << ((I1.estEgal(I2)) ? "Vrai" : "Faux") << endl;

  cout << "Test de estInclusStrc" << endl;
  cout << ((I1.estInclusStrc(I2)) ? "Vrai" : "Faux") << endl;

  cout << "Test de estDisjoint" << endl;
  cout << ((I1.estDisjoint(I2)) ? "Vrai" : "Faux") << endl;

  cout << "Test de estAccole" << endl;
  cout << ((I1.estAccole(I2)) ? "Vrai" : "Faux") <<endl;

  cout << "Test de estImbrique" << endl;
  cout << ((I1.estImbrique(I2)) ? "Vrai" : "Faux") <<endl;

  cout << "Test de translater" << endl;
  I1.translater(-2.5);
  cout << "[" << I1.getInf() << "," << I1.getSup() << "]" << endl;
  
  
  return 0;
}
