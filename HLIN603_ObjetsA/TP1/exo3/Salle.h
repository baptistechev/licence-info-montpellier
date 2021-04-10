#ifndef Salle_h
#define Salle_h
#include<iostream>
#include <string>
#include <map>
#include "Objet.h"
using namespace std;

class Salle
{
    private:
        int capacite = 10;
        map<int, Objet> objets;
        
    public:
        Salle();
        Salle(const int);
        virtual ~Salle();
        virtual void placer(Objet, int);
        virtual void enlever(int);
        virtual void affiche(ostream& os);
        virtual int nbObjets()const;

};

#endif