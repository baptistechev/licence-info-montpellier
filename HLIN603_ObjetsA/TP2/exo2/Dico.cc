#include "Dico.h"
#include <string>
using namespace std;

template<typename TypeCle, typename TypeValeur> 
void Dico<TypeCle, TypeValeur>::CherchCl(const TypeCle& cl, int& i, int& res)const{
    int j = hash(cl, capacite);
    i = j;
    res = 0;
    while(tabAssoc[i].getCle() != cleDefaut && tabAssoc[i].getCle() != cl && res!=2){
        i++;
        if(i == capacite) i = 0;
        if(i==j) res = 2;
    }
    if(tabAssoc[i].getCle() == cl) res = 1;
}

template<typename TypeCle, typename TypeValeur> 
int Dico<TypeCle, TypeValeur>::hash(TypeCle C, int tailleTab){}

template<typename TypeCle, typename TypeValeur>
Dico<TypeCle, TypeValeur>::Dico(): nbAssoc(0), capacite(10) {
    tabAssoc = new Assoc<TypeCle, TypeValeur>[capacite];
    for (size_t i = 0; i < capacite; i++)
    {
        tabAssoc[i].setCle(cleDefaut);
        tabAssoc[i].setValeur(valeurDefaut);
    }
}

template<typename TypeCle, typename TypeValeur>
Dico<TypeCle, TypeValeur>::Dico(const Dico<TypeCle, TypeValeur> &D) : nbAssoc(D.nbAssoc), capacite(D.capacite){
    tabAssoc = new Assoc<TypeCle, TypeValeur>[capacite];
    for (size_t i = 0; i < nbAssoc; i++) tabAssoc[i] = D.tabAssoc[i]; 
} 

template<typename TypeCle, typename TypeValeur>
Dico<TypeCle, TypeValeur>::~Dico(){ delete[] tabAssoc;}

template<typename TypeCle, typename TypeValeur>
void Dico<TypeCle, TypeValeur>::put (const TypeCle &cle, const TypeValeur &valeur){
    
    int j = hash(cle, capacite);
    while(j<capacite && tabAssoc[j].getCle() != cleDefaut ) j++;    
    if(j>=capacite || nbAssoc >= capacite){
        Assoc<TypeCle, TypeValeur> *T = new Assoc<TypeCle, TypeValeur>[capacite];
        for (size_t i = 0; i < capacite; i++)
        {
            T[i] = tabAssoc[i];
        }
        capacite *= 2;
        delete[] tabAssoc;
        tabAssoc = new Assoc<TypeCle, TypeValeur>[capacite];
        for (size_t i = 0; i < capacite; i++)
        {
            if(i < capacite/2){
                tabAssoc[i] = T[i];
            }else{
                tabAssoc[i].setCle(cleDefaut);
                tabAssoc[i].setValeur(valeurDefaut);
            }
        }
    }
    tabAssoc[j].setCle(cle);
    tabAssoc[j].setValeur(valeur);
    nbAssoc++;
}

template<typename TypeCle, typename TypeValeur>
TypeValeur Dico<TypeCle, TypeValeur>::get(const TypeCle &C)const{
    int i = 0, res = 0;
    CherchCl(C, i, res);
    return tabAssoc[i].getValeur();
} 

template<typename TypeCle, typename TypeValeur>
bool Dico<TypeCle, TypeValeur>::estVide()const{return nbAssoc==0;}

template<typename TypeCle, typename TypeValeur>
bool Dico<TypeCle, TypeValeur>::contient(const TypeCle& C)const{
    int i = 0, res = 0;
    CherchCl(C, i, res);
    return res == 1;
}

template<typename TypeCle, typename TypeValeur>
int Dico<TypeCle, TypeValeur>::taille()const{return nbAssoc;}

template<typename TypeCle, typename TypeValeur>
void Dico<TypeCle, TypeValeur>::affiche (ostream& os)const{
    if(estVide()) os << "Le dico est vide !";
    else{
        for (size_t i = 0; i < capacite; i++)
        {
            if(tabAssoc[i].getCle() != cleDefaut)
                os << tabAssoc[i] << endl;
        }
    }
}

// template<typename TypeCle, typename TypeValeur>
// Dico& Dico<TypeCle, TypeValeur>::operator=(const Dico &D){   
// }

template<typename TypeCle, typename TypeValeur> 
ostream& operator<<(ostream& os, const Dico<TypeCle, TypeValeur>& D){
    D.affiche(os);
    return os;
}
