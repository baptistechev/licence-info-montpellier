#ifndef CompteDepotCC_h
#define CompteDepotCC_h
#include "CompteDepot.h"

class CompteDepotCC : public virtual CompteDepot
{
    private:
        int numero;
    public:
        CompteDepotCC();
        virtual ~CompteDepotCC();
        virtual void deposer(const int);
};

#endif