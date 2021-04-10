#include "Salle.h"
#include <map>
using namespace std;

Salle::Salle(){}

Salle::Salle(const int cap) : capacite(cap){}

Salle::~Salle(){}

void Salle::placer(Objet o, int place){
    if(place < capacite)
        objets[place] = o;
}

void Salle::enlever(int place){
    if(place < capacite)
        if(objets.find(place) != objets.end())
            objets.erase(place);
        else
            cout << "pas d'objet à cette place !" <<endl;
    else
        cout << "capacite depasse !"<<endl;
}

void Salle::affiche(ostream& os){
    for (map<int,Objet>::iterator it=objets.begin(); it!=objets.end(); ++it)
        os << "[" << it->first << "] -> " << it->second << '\n';    
}

int Salle::nbObjets()const{
    return objets.size();
}