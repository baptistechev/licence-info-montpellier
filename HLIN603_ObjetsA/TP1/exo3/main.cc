#include "Objet.h"
#include "ObjetArt.h"
#include "ObjetRegretable.h"
#include "Salle.h"
using namespace std;

int main(int argc, char const *argv[])
{
    // Objet o2("desc", 2);
    // Objet *o = new Objet("description", 1);
    // cout << *o << endl;
    // cout << o2 << endl;

    Salle *s = new Salle();
    s->placer(ObjetArt("desc",2,"auteurC"), 8);
    s->placer(Objet("desc2",1), 6);
    s->placer(ObjetRegretable("desc",3,"jean", 2000), 1);

    s->enlever(1);
    s->enlever(1);

    s->affiche(cout);
    cout << s->nbObjets() << endl;
    return 0;
}
