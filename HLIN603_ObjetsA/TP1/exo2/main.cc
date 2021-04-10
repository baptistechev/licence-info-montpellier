#include <iostream>
#include "Compte.h"
#include "CompteRenum.h"
#include "CompteDepot.h"
#include "CompteRenumCC.h"
using namespace std;

int main(int argc, char const *argv[])
{
    // CompteDepot *c = new CompteDepot();
    // c->deposer(1000);
    // delete c;

    Compte *compteVP[10];
    for (size_t i = 0; i < 6; i++)
    {
        compteVP[i] = new Compte();
    }
    compteVP[6] = new CompteRenum();
    compteVP[7] = new CompteRenum();
    compteVP[8] = new CompteRenumCC();
    compteVP[9] = new CompteRenumCC();
    
    for (size_t i = 0; i < 10; i++)
    {
        compteVP[i]->deposer(1000);
        cout << compteVP[i]->getSolde() << endl;
    }

    return 0;
}
