#ifndef Assoc_h 
#define Assoc_h
using namespace std; 
#include<iostream>

template<typename TypeCle, typename TypeValeur> 
class Assoc{
    private:
        TypeCle cle; 
        TypeValeur valeur; 
    public:
        Assoc();
        Assoc(TypeCle, TypeValeur); 
        virtual ~Assoc ();
        virtual TypeCle getCle()const; 
        virtual void setCle(TypeCle); 
        virtual TypeValeur getValeur()const; 
        virtual void setValeur(TypeValeur); 
        virtual void affiche(ostream&)const;
        // virtual Assoc& operator=(const Assoc& A);
};

template<typename TypeCle, typename TypeValeur> 
ostream& operator<<(ostream&, const Assoc<TypeCle,TypeValeur>&);

#endif