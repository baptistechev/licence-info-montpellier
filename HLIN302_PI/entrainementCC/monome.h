#ifndef __MONOME_H__
#define __MONOME_H__

#include <string>
#include <iostream>

class Monome{

 private:
  std::string nom;
  float coef;
  int exp;
  Monome* suiv;

 public:

  //Constructeur
  Monome();
  Monome(std::string name,float c,int e,Monome* m);

  //Setters
  void setNom(std::string n);
  void setCoef(float c);
  void setExp(int e);
  void setSuiv(Monome* s);

  //Getters
  std::string getNom() const;
  float getCoef() const;
  int  getExp() const;
  Monome* getSuiv() const;

  //Methodes
  void affiche(bool courant) const;
  
};

#endif