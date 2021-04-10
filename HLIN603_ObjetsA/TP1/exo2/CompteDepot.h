#ifndef CompteDepot_h
#define CompteDepot_h
#include "Compte.h"

class CompteDepot : public virtual Compte
{
    private:
        int frais;
    public:
        CompteDepot();
        virtual ~CompteDepot();
        virtual void deposer(const int);
};

#endif