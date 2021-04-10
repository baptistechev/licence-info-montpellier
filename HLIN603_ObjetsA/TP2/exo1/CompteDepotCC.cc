#include "CompteDepotCC.h"
#include <iostream>
using namespace std;

CompteDepotCC::CompteDepotCC() : CompteDepot(), numero(1234) {}
CompteDepotCC::~CompteDepotCC(){cout<<typeid(this).name()<<endl;}
void CompteDepotCC::deposer(const int){}