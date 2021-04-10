#include "Objet.h"

Objet::Objet() : desc(""),ref(0){}

Objet::Objet(const string desc, const int ref) : desc(desc),ref(ref){}

Objet::~Objet(){}

void Objet::setDesc(const string desc){ this->desc= desc;}
void Objet::setRef(const int ref){ this->ref= ref;}
string Objet::getDesc() const{ return desc;}
int Objet::getRef() const{ return ref;}

ostream& operator<<(ostream& os, const Objet& obj){
    os << obj.getRef() << " : " << obj.getDesc() << endl;
    return os;
}

istream& operator>>(istream& is, Objet& obj){
    int ref; string desc;
    is >> ref >> desc;
    obj.setRef(ref); obj.setDesc(desc);
    return is;
}