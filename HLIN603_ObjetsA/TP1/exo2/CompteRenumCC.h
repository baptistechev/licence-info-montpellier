#ifndef CompteRenumCC_h
#define CompteRenumCC_h
#include "CompteRenum.h"

class CompteRenumCC : public virtual CompteRenum
{
    private:
        int frais;
    public:
        CompteRenumCC();
        virtual ~CompteRenumCC();
        virtual void deposer(const int, const int);
};

#endif