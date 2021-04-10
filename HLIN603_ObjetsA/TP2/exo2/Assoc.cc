#include "Assoc.h"
using namespace std;

template<typename TypeCle, typename TypeValeur> 
Assoc<TypeCle, TypeValeur>::Assoc(){}

template<typename TypeCle, typename TypeValeur> 
Assoc<TypeCle, TypeValeur>::Assoc(TypeCle cle, TypeValeur valeur) : cle(cle), valeur(valeur) {}

template<typename TypeCle, typename TypeValeur> 
Assoc<TypeCle, TypeValeur>::~Assoc (){}

template<typename TypeCle, typename TypeValeur> 
TypeCle Assoc<TypeCle, TypeValeur>::getCle()const{ return cle;}

template<typename TypeCle, typename TypeValeur> 
void Assoc<TypeCle, TypeValeur>::setCle(TypeCle c){this->cle = c;}

template<typename TypeCle, typename TypeValeur> 
TypeValeur Assoc<TypeCle, TypeValeur>::getValeur()const{return valeur;}

template<typename TypeCle, typename TypeValeur> 
void Assoc<TypeCle, TypeValeur>::setValeur(TypeValeur v){this->valeur = v;}

template<typename TypeCle, typename TypeValeur> 
void Assoc<TypeCle, TypeValeur>::affiche(ostream& os)const{os << cle << " => " << valeur << endl;}

// template<typename TypeCle, typename TypeValeur> 
// Assoc<TypeCle, TypeValeur>& Assoc<TypeCle, TypeValeur>::operator=(const Assoc<TypeCle, TypeValeur>& A){
//     return *new Assoc<TypeCle, TypeValeur>(A.cle, A.valeur);
// }


template<typename TypeCle, typename TypeValeur> 
ostream& operator<<(ostream& os, const Assoc<TypeCle,TypeValeur>& assoc){
    os << assoc.getCle() << " => " << assoc.getValeur();
    return os;
}
