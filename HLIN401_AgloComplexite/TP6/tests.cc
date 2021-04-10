#include <iostream>
#include <sstream>
#include <cmath>
#include <cfloat>
#include <algorithm>

#include "ensembles.h"
#include "matrice.h"
#include "points.h"
#include "tsp.h"

#define TEMPS(t) \
  (double) (t) * 1000 / CLOCKS_PER_SEC << " ms"

#define LGR(d) ((d==FLT_MAX)?"INF":to_string(d))

using namespace std;

coord* choixPoints(int& n)
{
  while (n < 1)
  {
    cout << "Entrer un nombre de points (> 0) : ";
    cin >> n;
  }

  int t;
  do 
  {
    cout << "Type de points (1. fixés ; 2. aléatoires) : ";
    cin >> t;
  } while (t != 1 and t != 2);


  if (t == 1) srand(0);
  else srand(time(NULL));
  coord* P = new coord[n];
  pointsAleatoires(n, P);
  dessinPoints(n, P);
  cout << n << " points (cf Points.svg) : "; 
  affichePoints(n, P);
  cout << endl;
  return P;
}


int main(int argc, char** argv)
{
  int q, n, n5, min, t;
  float d, d1;
  clock_t t1, t2, t3;
  coord* P;
  float** D;
  int** Prec;
  int* circuit;



  q = (argc>1) ? atoi(argv[1]) : 8;
  n = (argc>2) ? atoi(argv[2]) : 0;

  while(true)
  {
    while (q > 7)
    {
      cout << "Entrer le numéro de question à tester (0 pour quitter) : ";
      cin >> q;
      if (q == 0) return 0;
    }
    
    if (q == 1)
    {
      ensemble E;
      cout << "Entrer un entier positif : ";
      cin >> E;
      cout << "L'entier " << E << " représente l'ensemble " << str(E) << endl << endl << endl;
      q = 8;
      continue;
    }

    if (q == 2)
    {
        coord p1, p2;
        cout << "Entrer les coordonnées de deux points (x0, y0) et (x1, y1)" << endl;
        cout << "  x1 : "; cin >> p1.x;
        cout << "  y1 : "; cin >> p1.y;
        cout << "  x2 : "; cin >> p2.x;
        cout << "  y2 : "; cin >> p2.y;
        cout << "La distance entre " << p1 << " et " << p2 << " est : " 
             << distance(p1, p2) << " (à vérifier !)" << endl << endl << endl;
    q = 8;
        continue;
      }

    P = choixPoints(n);

    n5 = (n>5)?5:n;

    D = matrice<float>(1 + plein(n-1), n);
    initialise(1+plein(n-1), n, D, FLT_MAX);
    Prec = matrice<int>(1 + plein(n-1), n);
    circuit = new int[n];
    for(int i=0; i < n; i++) circuit[i] = i; // pour éviter le segfault quand algos non implémentés
    
    t1 = clock();  
    d = tsp(n, P, D, Prec, min);
    t1 = clock() - t1;

    t2 = clock();
    tsp_rec(circuit, n, D, Prec, min);
    t2 = clock() - t2;

    switch(q)
    {
      case 3:
        cout << "Contenu de la matrice D " << ((n > 5)?"(extrait : 5 premiers points) ":"") << ":" << endl;
        afficheMatrice(n5, 1<<(n5-1), D);
        break;

      case 4:
        cout << "Longueur du circuit le plus court : " << LGR(d) << endl;
        break;

      case 5:
        cout << "Longueur du circuit le plus court : " << LGR(d) << endl;
        cout << "Deuxième point du circuit : " << P[min] << endl;
        cout << "Contenu de la matrice Prec " << ((n > 5)?"(extrait : 5 premiers points) ":"") << ":" << endl;
        afficheMatrice(n5, 1<<(n5-1), Prec);
        break;

      case 6:
        cout << "Longueur du circuit le plus court : " << LGR(d) << endl;
        cout << "Circuit le plus court : ";
        for (int i=0; i < n; i++) cout << circuit[i] << " → ";
        cout << circuit[0] << endl;
        dessinTsp(n, P, circuit);
        cout << "Circuit dessiné dans le fichier Circuit.svg" << endl;
        break;

      case 7:
        t3 = clock();
        d1 = tsp_bruteforce(n, P);
        t3 = clock() - t3;
        cout << "Longueur du circuit le plus court :" << endl
             << "    calculé par programmation dynamique : " << LGR(d) << endl
             << "    calculé par recherche exhaustive : " << LGR(d1) << endl;
        cout << "Comparaison des temps de calcul : " << endl
             << "    programmation dynamique : " << TEMPS(t1+t2) 
                        << " (dont reconstruction : " << TEMPS(t2) << ")" << endl
             << "    recherche exhaustive : " << TEMPS(t3) << endl;
        break;
    }
      
    q = 8;
    n = 0;
    cout << endl << endl;
  }

  return 0;
}

#undef TEMPS
