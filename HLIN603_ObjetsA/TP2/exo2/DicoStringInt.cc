#include <string>
#include "Dico.cc"
#include <iostream>
using namespace std;

template<> int Dico<string, int>::hash(string C, int tailleTab){
    int i =0;
    for (int j = 0; j < C.length(); j++) i+= (j+1) * C[j];
    return (i%tailleTab);
}

template<> string Dico<string, int>::cleDefaut = "rien";
template<> int Dico<string, int>::valeurDefaut = 0;
template class Dico<string, int>;
template ostream& operator<< (ostream&, const Dico<string, int>&);