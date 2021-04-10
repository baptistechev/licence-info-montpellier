#ifndef CompteDepotRemunCC_h
#define CompteDepotRemunCC_h_h
#include "CompteDepotCC.h"
#include "CompteDepotRemun.h"

class CompteDepotRemunCC : public virtual CompteDepotCC, public virtual CompteDepotRemun
{
    public:
        CompteDepotRemunCC();
        virtual ~CompteDepotRemunCC();
        virtual void deposer(const int);
};

#endif