#include "CompteDepotRemunCC.h"
#include <iostream>
using namespace std;

CompteDepotRemunCC::CompteDepotRemunCC() : CompteDepotCC(),CompteDepotRemun(){}
CompteDepotRemunCC::~CompteDepotRemunCC(){
    cout<<typeid(this).name()<<endl;
}
void CompteDepotRemunCC::deposer(const int){}