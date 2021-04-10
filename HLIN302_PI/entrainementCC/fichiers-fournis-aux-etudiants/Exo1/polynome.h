#ifndef __POLYNOME_H__
#define __POLYNOME_H__

#include <string>
#include "monome.h"

class Polynome{

 private:
  Monome* tete;

  void ajouterApresPos(Monome m,Monome* pos);
  void supprimerApresPos(Monome* pos);
  
 public:
  Polynome();
  Polynome(Monome t);
  Polynome(Polynome &p);

  Polynome& operator=(Polynome&);
  
  void ajouterDeb(Monome m);
  void ajouterFin(Monome m);
  void ajouterPolynomeFin(Polynome p);
  void suppr();
  
  void afficher() const;

  ~Polynome();
  
};

#endif