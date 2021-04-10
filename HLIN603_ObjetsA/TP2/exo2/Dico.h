#ifndef Dico_h 
#define Dico_h
using namespace std; 
#include<iostream>
#include "Assoc.h"

template<typename TypeCle, typename TypeValeur> 
class Dico {
    private :
        Assoc<TypeCle, TypeValeur> * tabAssoc; 
        int nbAssoc; 
        int capacite;

        void CherchCl(const TypeCle& cl, int& i, int& res)const;
        static TypeCle cleDefaut; 
        static TypeValeur valeurDefaut;

    public :
        static int hash(TypeCle, int); 
        Dico();
        Dico(const Dico & D); 
        virtual ~Dico();
        virtual void put (const TypeCle &, const TypeValeur &); 
        virtual TypeValeur get(const TypeCle &)const; 
        virtual bool estVide()const;
        virtual bool contient(const TypeCle& C)const; 
        virtual int taille()const; 
        virtual void affiche (ostream&)const; 
        // virtual Dico& operator=(const Dico & D);


}; 

template<typename TypeCle, typename TypeValeur> 
ostream& operator<<(ostream& , const Dico<TypeCle, TypeValeur>& );

#endif