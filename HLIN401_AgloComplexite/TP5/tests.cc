#include <iostream>
#include <fstream>
#include "edition.h"

string lecture(string nom)
{
  ifstream fichier;
  fichier.open(nom);
  string ligne, sortie;

  while (getline(fichier, ligne))
    sortie.append(ligne);

  fichier.close();
  return sortie;
}

int main(int argc, char** argv)
{

  int** E;
  string s1, s2, aligne;
  int q, a, b, c, m, n, i, j, val, d;

  if (argc == 3)
  {
    string s1 = lecture(argv[1]);
    string s2 = lecture(argv[2]);
    m = s1.size(); n = s2.size();

    cout << "La séquence " << argv[1] << " est de longueur " << m << "." << endl;
    cout << "La séquence " << argv[2] << " est de longueur " << n << "." << endl;

    E = matrice(m, n);
    d = distanceEdition(s1, s2, E);
    cout << "Leur distance d'édition est " << d << "." << endl;
    desalloue(m, n, E);

    return 0;
  }

  do
  {
    cout << "Entrer le numéro de question à tester (0 pour quitter) : ";
    cin >> q;

    switch (q)
    {
      case 1:
        cout << "Entrer a : "; cin >> a;
        cout << "Entrer b : "; cin >> b;
        cout << "Entrer c : "; cin >> c;
        cout << "  min(" << a << "," << b << "," << c << ") = " << min(a,b,c) << endl << endl;
        break;

      case 2:
        cout << "Entrer le nb de lignes du tableau E : "; cin >> m;
        cout << "Entrer le nb de colonnes du tableau E : "; cin >> n;
        cout << "Entrer la ligne i : "; cin >> i;
        cout << "Entrer la ligne j : "; cin >> j;
        E = matrice(m, n);
        initialise(m, n, E, 0);
        E[i][j] = 1;
        affiche(m, n, E);
        val = valeur(E, i, j);
        cout << "  valeur(E, " << i << ", " << j << ") = " << val << endl << endl;
        desalloue(m, n, E);
        break;

      case 3:
        cout << "Entrer la première chaîne de caractère : "; cin >> s1;
        cout << "Entrer la seconde chaîne de caractère : "; cin >> s2;

        m = s1.size(); n = s2.size();
        E = matrice(m, n);
        d = distanceEdition(s1, s2, E);
        cout << "  distanceEdition(" << s1 << ", " << s2 << ") = " << d << endl << endl;
	affiche(m,n,E);
        desalloue(m, n, E);
        break;

      case 4:
        cout << "Entrer la première chaîne de caractère : "; cin >> s1;
        cout << "Entrer la seconde chaîne de caractère : "; cin >> s2;

        m = s1.size(); n = s2.size();
        E = matrice(m, n);
        d = distanceEdition(s1, s2, E);
        cout << "  distanceEdition(" << s1 << ", " << s2 << ") = " << d << endl;
	affiche(m,n,E);
        aligne = alignement(s1, s2, E);
        cout << "  alignement : " << s1 << endl
             << "               " << s2 << endl << endl;
        desalloue(m, n, E);
        break;

      case 5:
        cout << "Entrer la première chaîne de caractère : "; cin >> s1;
        cout << "Entrer la seconde chaîne de caractère : "; cin >> s2;

        m = s1.size(); n = s2.size();
        E = matrice(m, n);
        d = distanceEdition(s1, s2, E);
        cout << "  distanceEdition(" << s1 << ", " << s2 << ") = " << d << endl;
        aligne = alignement(s1, s2, E);
        cout << "  alignement : " << s1 << endl
             << "               " << aligne << endl
             << "               " << s2 << endl << endl;
        desalloue(m, n, E);
        break;
    }

  } while(q > 0);
  return 0;
}

