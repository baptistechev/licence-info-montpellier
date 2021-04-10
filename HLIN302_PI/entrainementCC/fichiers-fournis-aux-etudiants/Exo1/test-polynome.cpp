#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "polynome.h"
#include "monome.h"

using namespace std;

// Supprime les espaces et les '*' et remplace les ',' par des '.'
// La chaine passé en paramètre est modifiée sur place et également renvoyée.
string &nettoie_polynome(string &s) {
  size_t p = 0, n = s.length();  
  for (size_t i = 0; i < n; ++i) {
    if ((s[i] > ' ') && (s[i] != '*')) {
      if (s[i] == ',') {
        s[i] = '.';
      }
      s[p++] = s[i];
    }
  }
  s = s.substr(0, p);
  return s;
}

// Renvoie le premier monome et modifie la chaine pour ne conserver que le reste du polynome
string get_monome(string &s) {
  string res;
  size_t p = s.find_first_of("+-", 1);
  if (p != string::npos) {
    res = s.substr(0, p);
    s = s.substr(p);
  } else {
    res = s;
    s = "";
  }
  return res;  
}

// Renvoie le coefficient du monome et modifie la chaine pour ne conserver que le reste du monome
float get_coefficient(string &s) {
  char *ptr;
  float res = strtof(s.c_str(), &ptr);
  if (ptr) {
    if (ptr == s.c_str()) {
      res = (*ptr ? 1 : 0);
    }
    s = s.substr(ptr - s.c_str());
  } else {
    s = "";
  }
  return res;
}

// Renvoie le nom de la variable du monome et modifie la chaine pour ne conserver que le reste du monome
string get_variable(string &s) {
  string res;
  size_t p = s.find_first_of("0123456789+-^");
  if (p != string::npos) {
    res = s.substr(0, p);
    s = s.substr(p);
  } else {
    res = s;
    s = "";
  }
  return res;
}

// Renvoie la valeur de l'exposant du monome et modifie la chaine pour ne conserver que le reste du monome (a priori la chaine vide)
int get_exposant(string &s) {
  int res;
  char *ptr;
  if (s[0] == '^') {
    res = strtol(s.c_str()+1, &ptr, 10);
    if (ptr) {
      if (ptr == s.c_str()) {
        res = (*ptr ? 1 : 0);
      }
      s = s.substr(ptr-s.c_str());
    } else {
      s = "";
    }
  } else {
    res = 1;
  }
  return res;
}


int main(int argc, char **argv) {
  // à compléter
  
  /*
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
  */
  
  if(argc<2) return 1;
  ifstream fc(argv[1]);
  if(!fc.is_open()){
    cerr<<" error : impossible d'ouvrir ' "<<argv[1]<<"'"<<endl;
  }
  Polynome P;
  float coef;
  std::string var;
  int exp;
  while(!fc.eof()){
    string s;
    getline(fc,s);
    s=nettoie_polynome(s);
    while(!s.empty()){
      coef = get_coefficient(s);
      var= get_variable(s);
      exp = get_exposant(s);
      Monome *M = new Monome(var,coef,exp,NULL);
      P.ajouterFin(*M);
    }
  }
  fc.close();
  P.afficher();  
  
  return 0;
}
