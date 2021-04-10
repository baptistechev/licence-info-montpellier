#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

void voisinsRandom(int n, int m, vector<int>voisins[])
{
  // srand(time(NULL));
  int x,y;
  for(int i=0;i<m;i++)
  {
    do
    {
      x=rand()%n;
      y=rand()%n;
    }
    while(x==y || find(voisins[x].begin(),voisins[x].end(),y)!=voisins[x].end());
    voisins[x].push_back(y);
    voisins[y].push_back(x);
  }
}

void parcoursLargeur(int n,vector<int> voisins[], int niveau[], int ordre[], int pere[]){

  int dv[n];
  queue<int> AT;
  for (int i = 0; i < n; i++)
  {
    dv[i] = 0;
    ordre[i] = -1;
    niveau[i] = -1;
    pere[i] = -1;
  }
  dv[0]=1;ordre[0]=1;pere[0]=0;niveau[0]=0; 
  AT.push(0);
  int t =2, v;
  while(!AT.empty()){
    v = AT.front();
    AT.pop();
    for(size_t i =0;i<voisins[v].size();i++){
      if(dv[voisins[v][i]] ==0){
        dv[voisins[v][i]] =1;
        AT.push(voisins[v][i]);
        ordre[voisins[v][i]] = t;
        t++;
        pere[voisins[v][i]] = v;
        niveau[voisins[v][i]] = niveau[v] +1;
      }
    }
  }
}

void ecritureNiveaux(int n, int niveau[]){
  int cpt[n];int nj = 0;
  for (int i = 0; i < n; i++)
  {
    cpt[i] = 0;
  }
  for (int i = 0; i < n; i++)
  {
    if(niveau[i] == -1)
      nj++;
    else
      cpt[niveau[i]]++;
  }
  for (int i = 0; i < n; i++)
  {
    if(cpt[i] != 0)
      cout << "Il y a " << cpt[i] << " sommets au niveau " << i<<endl;
  }
  cout << "Il y a " << nj << " sommets qui ne sont pas dans la composante de 0"<<endl;
  
}

int main()
{
  int n;                                    // Le nombre de sommets.
  int m;                                    // Le nombre d'aretes.
  cout << "Entrer le nombre de sommets: ";
  cin >> n;
  cout << "Entrer le nombre d'aretes: ";
  cin >> m;
  vector<int> voisins[n];                   // Les listes des voisins. 
  int pere[n];                              // L'arbre en largeur.
  int ordre[n];                             // L'ordre de parcours.
  int niveau[n];                            // Le niveau du point.

  if(m>=n){
    cout << "Trop d'aretes, creation de boucles"<<endl;
    return 1;
  }
  voisinsRandom(n, m, voisins);
  parcoursLargeur(n,voisins, niveau, ordre, pere);
  ecritureNiveaux(n,niveau);
  
//une modif
  // for (int i = 0; i < n; i++)
  // {
  //   cout << "voisins de " << i << " : ";
  //   for (size_t j = 0; j < voisins[i].size(); j++)
  //   {
  //     cout << voisins[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  
  // for(int i =0;i<n;i++){
  //   cout << i << " : " << pere[i] << endl;
  // }  
  
  return EXIT_SUCCESS;
}
