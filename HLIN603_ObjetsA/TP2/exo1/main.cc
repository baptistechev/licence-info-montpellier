#include <iostream>
#include "Compte.h"
#include "CompteRenum.h"
#include "CompteDepot.h"
#include "CompteDepotRemun.h"
#include "CompteDepotCC.h"
#include "CompteDepotRemunCC.h"
using namespace std;

int main(int argc, char const *argv[])
{

    // CompteDepotRemun *c = new CompteDepotRemun();
    // c->CompteDepot::deposer(2000);
    // cout << c->getSolde() << endl;

    CompteDepotRemunCC *c = new CompteDepotRemunCC();
    delete c;

    return 0;
}
