#ifndef CompteDepotRemun_h
#define CompteDepotRemun_h
#include "CompteRenum.h"
#include "CompteDepot.h"

class CompteDepotRemun : public virtual CompteRenum, public virtual CompteDepot
{
    public:
        CompteDepotRemun();
        virtual ~CompteDepotRemun();
        virtual void deposer(const int);
};

#endif