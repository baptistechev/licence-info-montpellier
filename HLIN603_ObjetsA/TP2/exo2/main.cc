#include "Assoc.h"
#include "Dico.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    // Assoc<string, int> *a = new Assoc<string, int>("hello", 0);
    // cout << *a << endl;

    Dico<string, int> *d = new Dico<string, int>();
    
    d->put("test", 1);
    d->put("machin", 2);
    d->put("orange", 3);
    d->put("noir", 4);
    d->put("rouge", 5);
    d->put("bleu", 6);
    d->put("violet", 7);
    d->put("dark", 8);
    d->put("wtf", 9);
    d->put("yellow", 10);
    d->put("purple", 11);

    cout << *d << endl;
    cout << d->get("test") << endl;
    cout << d->contient("khlbli") << endl;

    delete d;
    return 0;
}
