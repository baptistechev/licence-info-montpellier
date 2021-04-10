#ifndef CompteRenum_h
#define CompteRenum_h
#include "Compte.h"

class CompteRenum : public virtual Compte
{
    private:
        float taux;
    public:
        CompteRenum();
        virtual ~CompteRenum();
        virtual float getTaux()const;
        virtual void deposer(const int);
};

#endif