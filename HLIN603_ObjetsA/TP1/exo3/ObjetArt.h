#ifndef ObjetArt_f
#define ObjetArt_f
#include<iostream>
#include <string>
#include "Objet.h"
using namespace std;

class ObjetArt : public virtual Objet
{

    private:
        string auteur;
    public:
        ObjetArt();
        ObjetArt(const string, const int, const string);
        virtual ~ObjetArt(); 
        virtual void setAuteur(const string);
        virtual string getAuteur() const;

};

#endif