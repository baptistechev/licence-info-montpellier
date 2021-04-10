#include<iostream>
#include"Vers.h"
#include"Strophe.h"
using namespace std;

int main(int argc, char** argv){

    Strophe *s = new Strophe();
    s->saisie(cin);
    s->affiche(cout);

}