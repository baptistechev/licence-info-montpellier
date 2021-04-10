#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "Polynome.h"
#include "Monome.h"

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
   if(argc!=2){
  }

  ifstream fich(argv[1]);
  if(!fich.is_open()){
    cerr<<" error : impossible d'ouvrir ' "<<argv[1]<<"'"<<endl;
  }
  Polynome P;
  while(!fich.eof()){
    string s,m;
    getline(fich,s);
    s=nettoie_polynome(s);
    while(!s.empty()){
      Monome *M= new Monome(get_coefficient(s),get_exposant(s),get_variable(s));
      P.ajoutFin(*M);
      m=get_monome(s);
    }
  }
  P.affichePoly();
  return 0;
}
