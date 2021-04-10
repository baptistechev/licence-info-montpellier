#ifndef ObjetRegretable_f
#define ObjetRegretable_f
#include<iostream>
#include <string>
#include "Objet.h"
using namespace std;

class ObjetRegretable : public virtual Objet
{

    private:
        string donateur;
        int annee;
    public:
        ObjetRegretable();
        ObjetRegretable(const string, const int, const string, const int);
        virtual ~ObjetRegretable(); 
        virtual void setDonateur(const string);
        virtual void setAnnee(const int);
        virtual string getDonateur() const;
        virtual int getAnnee() const;
};

#endif