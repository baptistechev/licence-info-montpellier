#include <iostream>
#include <cstdlib>
#include "TrisRang.h"

using namespace std;

void tableauManuel(int n, int* T)
{
  for (int i = 0; i < n; i++)
  {
    cout << "Valeur de T[" << i << "] : ";
    cin >> T[i];
  }
}

void tableauAleatoire(int n, int* T)
{
  for (int i=0; i < n; i++)
    T[i] = rand() % (4*n);
}

void tableauCroissant(int n, int* T)
{
  T[0] = rand() % 5;
  for (int i=1; i < n; i++)
    T[i] = T[i-1] + (rand() % 5);
}

void tableauDecroissant(int n, int* T)
{
  T[n-1] = rand() % 5;
  for (int i=n-2; i >= 0; i--)
    T[i] = T[i+1] + (rand() % 5);
}

void copier(int n, int* T, int* T2)
{
  for (int i = 0; i < n; i++) 
    T2[i] = T[i];
}

void afficher(int n, int* T)
{
  cout << "[";
  for(int i=0;i<n-1;i++) cout << T[i] << ",";
  cout << T[n-1] << "]" << endl;
}

bool estTrie(int n, int* T)
{
  for (int i = 0; i < n-1; i++)
    if (T[i] > T[i+1]) return false;
  return true;
}

int main()
{
  srand(time(NULL));

  int n, type = 5;
  int* T;
  
  while (type > 4)
  {
    cout << "Taille du tableau à construire (0 pour quitter) : ";
    cin >> n;
    if (n <= 0) return 0;

    cout << "Type de tableau à construire :" << endl
         << "    1. Remplissage manuel" << endl
         << "    2. Remplissage aléatoire" << endl
         << "    3. Ordre croissant" << endl
         << "    4. Ordre décroissant" << endl
         << "Choix : ";
    cin >> type;
  }

  T = new int[n];

  switch (type)
  {
    case 1: tableauManuel(n, T); break;
    case 2: tableauAleatoire(n, T); break;
    case 3: tableauCroissant(n, T); break;
    case 4: tableauDecroissant(n, T); break;
  }

  cout << "Tableau T : "; afficher(n, T);

  int choix = 4;
  int* T1 = new int[n];
  int* T2 = new int[n];
  while (choix > 3)
  {
    cout << "Opération à effectuer (0 pour quitter) : " << endl
         << "    1. Tri fusion" << endl
         << "    2. Calcul de rang" << endl
         << "    3. Tri rapide" << endl
         << "Choix : ";
    cin >> choix;
    if (choix <= 0) return 0;

    clock_t t1, t2, t3;
    int r1, r2, k;

    switch (choix)
    {
      case 1: 
        copier(n, T, T1);
        t1 = clock();
        trifusion(n, T1);
        t2 = clock();
        cout << endl;
        if (estTrie(n, T1)){
          cout << "Tableau correctement trié, en temps " << (double)(t2-t1)*1000000 / CLOCKS_PER_SEC << " µs" << endl;
	afficher(n, T1);
        }else
        {
          cout << "ERREUR, tableau non trié : "; 
          afficher(n, T1);
        }
        cout << endl;
        break;

      case 2:
        k = 0;
        while (k < 1 or k > n)
        {
          cout << "Choisir un rang entre 1 et " << n << " : ";
          cin >> k;
        }
        t1 = clock();
        r1 = rang(k, n, T, FIXE);
        t2 = clock();
        r2 = rang(k, n, T, ALEATOIRE);
        t3 = clock();

        if (r1 != r2) 
        {
          cout << "ERREUR : résultat " << r1 << " avec pivot FIXE et " << r2 << " avec pivot ALEATOIRE." << endl;
          delete T;
          return 1;
        }

        cout << endl;
        cout << "Élément de rang " << k << " calculé (à vérifier !) : " << r1 << endl;
        cout << "    temps avec pivot FIXE :      " << (double)(t2-t1)*1000000 / CLOCKS_PER_SEC << "µs" << endl;
        cout << "    temps avec pivot ALEATOIRE : " << (double)(t3-t2)*1000000 / CLOCKS_PER_SEC << "µs" << endl;
        cout << endl; 
        break;

      case 3:
        copier(n, T, T1);
        copier(n, T, T2);

        t1 = clock();
        trirapide(n, T1, FIXE);
        t2 = clock();
        trirapide(n, T2, ALEATOIRE);
        t3 = clock();

        cout << endl;
        if (not estTrie(n, T1)) 
        { cout << "ERREUR avec pivot FIXE : "; afficher(n, T1); }
        if (not estTrie(n, T2)) 
        { cout << "ERREUR avec pivot ALEATOIRE : "; afficher(n, T2); }

        if (estTrie(n, T1) and estTrie(n, T2))
        {
          cout << "Tableau correctement trié" << endl;
          cout << "Temps de calcul :" << endl;
          cout << "  avec pivot FIXE : " << (double)(t2-t1)*1000000 / CLOCKS_PER_SEC << "µs" << endl;
          cout << "  avec pivot ALEATOIRE : " << (double)(t3-t2)*1000000 / CLOCKS_PER_SEC << "µs" << endl;
        }
        
        cout << endl;
        break;
      }

    choix = 4;

  }
  
  delete T;
  delete T1;
  delete T2;
  return 0;
}
