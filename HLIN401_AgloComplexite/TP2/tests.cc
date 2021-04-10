#include <iostream>
#include <fstream>
#include "Tas.h"

using namespace std;

void dessiner(int n, int* T, string name)
{
  ofstream output;
  output.open(name + ".dot");
  output << "digraph G {" << endl;
  output << "  node [style=filled];" << endl;
  
  output << "  N0 [label = \"" << T[0] << "\"];" << endl;

  for (int i = 0; i < (n+1)/2; i++)
  {
    if (2*i+1 < n) {
      output << "  N" << 2*i+1 << " [label = \"" << T[2*i+1] << "\"];" << endl;
      output << "  N" << i << " -> N" << 2*i+1 << ";" << endl;
    } else {
      output << "  N" << 2*i+1 << " [style = invis];" << endl;
      output << "  N" << i << " -> N" << 2*i+1 << " [style=invis];" << endl;
    }
    output << "  F" << i << " [style=invis];" << endl;
    output << "  N" << i << " -> F" << i << " [style=invis];" << endl;
    if (2*i+2 < n) {
      output << "  N" << 2*i+2 << " [label = \"" << T[2*i+2] << "\"];" << endl;
      output << "  N" << i << " -> N" << 2*i+2 << ";" << endl;
    } else {
      output << "  N" << 2*i+2 << " [style = invis];" << endl;
      output << "  N" << i << " -> N" << 2*i+2 << " [style=invis];" << endl;
    }
  }

  output << "}" << endl;
  output.close();

  if (!system(NULL)) exit (EXIT_FAILURE);
  string s = "dot -Tpdf " + name + ".dot > " + name + ".pdf";
  int i = system(s.c_str());
  if (i != 0) exit (EXIT_FAILURE);
}

void affichage(int n, int* T)
{
  dessiner(n, T, "Arbre");
  cout << "Arbre.pdf mis à jour" << endl
       << "Tableau T : ";
  afficher(n, T);
}

void question1(int n, int* T)
{
  cout << "Tableau T : ";
  afficher(n, T);
}
  
void question2(int n, int* T)
{
  cout << "Tableau T est tas max : " << boolalpha << estTasMax(n, T) << endl;
  cout << "Tableau T est tas min : " << boolalpha << estTasMin(n, T) << endl;
}

void question3(int n, int* T)
{
  tableauManuel(n, T);
  affichage(n, T);
}

void question4(int n, int* T)
{
  int m, M;
  cout << "Valeur minimale : ";
  cin >> m;
  cout << "Valeur maximale : ";
  cin >> M;
  tableauAleatoire(n, T, m, M);
  affichage(n, T);
}

void question5(int n, int* T)
{
  int i;
  cout << "Choisir une case à entasser : ";
  cin >> i;
  entasser(n, T, i);
  affichage(n, T);
}

void question6(int n, int* T)
{
  tas(n, T);
  affichage(n, T);
}

void question7(int n, int* T)
{
  int *Ttrie = trier(n, T);
  dessiner(n, Ttrie, "ArbreTrie");
  cout << "Résultat dessiné dans ArbreTrie.pdf" << endl
       << "Tableau Ttrie : ";
  afficher(n, Ttrie);
}

void question8(int n, int* T)
{
  trierSurPlace(n, T);
  affichage(n, T);
}


void question(int q, int n, int* T)
{
  switch(q)
  {
    case 1: question1(n, T); break;
    case 2: question2(n, T); break;
    case 3: question3(n, T); break;
    case 4: question4(n, T); break;
    case 5: question5(n, T); break;
    case 6: question6(n, T); break;
    case 7: question7(n, T); break;
    case 8: question8(n, T); break;
  }
}

int main()
{

  srand(time(NULL));
  int* T1 = new int[10]{7,12,4,8,10,2,1,1,3,9};
  int* T2 = new int[10]{9,7,8,6,4,0,2,3,5,1};

  int c,q;

  cout << "Choisir un type de tableau :" << endl
       << "    1. tableau test fixé" << endl
       << "    2. tas test fixé" << endl
       << "    n. Tableau de taille n rempli de 0 (n > 2)" << endl
       << "Entrer la valeur choisie (0 pour sortir) : ";
  cin >> c;

  int* T;
  int n;

  switch (c)
  {
    case 0: return 0;
    case 1: T = T1; n = 10; break;
    case 2: T = T2; n = 10; break;
    default: 
      n = c;
      T = new int[n];
      for (int i=0; i<n; i++) T[i] = 0;
      break;
  }

  dessiner(n, T, "Arbre");
  cout << endl << "Tableau de taille " << n << " dessiné comme arbre semi-complet dans Arbre.pdf" << endl << endl;

  cout << "Liste des questions :" << endl
       << "    1. Afficher le tableau" << endl
       << "    2. Tester si le tableau est un tas" << endl
       << "    3. Remplir le tableau à la main" << endl
       << "    4. Remplir le tableau aléatoirement" << endl
       << "    5. Entasser un élément" << endl
       << "    6. Transformer le tableau en tas" << endl
       << "    7. Trier le tableau" << endl
       << "    8. Trier le tableau sur place" << endl;

  while (1)
  {
    cout << endl << "Choisir une question (≤ 0 ou > 8 pour sortir) : ";
    cin >> q;
    
    if (q <= 0 or q > 8) return 0;

    question(q, n, T);
  }
}

