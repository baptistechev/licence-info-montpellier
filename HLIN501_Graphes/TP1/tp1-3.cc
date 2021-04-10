#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void grapheRandom(int n, int m, int edge[][2]){
  srand(time(NULL));
  for(int i =0; i<m; i++){
    edge[i][0] = rand()%n;
    edge[i][1] = rand()%n;
  }
}

void composante(int n, int m, int edge[][2], int comp[], vector<int> L[], int t[]){

  for(int i=0;i<n;i++){
    comp[i] = i;
    L[comp[i]].push_back(i);
    t[comp[i]] = 1;
  }

  int e, aux;
  for(int i = 0; i<m; i++){
    if(comp[edge[i][0]] != comp[edge[i][1]]){
      if(t[comp[edge[i][0]]] > t[comp[edge[i][1]]]){
	e = edge[i][0];
	edge[i][0] = edge[i][1];
	edge[i][1] = e;
      }
      aux = comp[edge[i][0]];
      t[comp[edge[i][1]]] = t[comp[edge[i][1]]] + t[aux];
      while(L[aux].empty() == 0){
	comp[L[aux].back()] = comp[edge[i][1]];
	L[comp[edge[i][1]]].push_back(L[aux].back());
	L[aux].pop_back();
      }
    }
  }
  
}

void ecritureTailles(int n, int m, int comp[]){
  int aux[n];
  for(int i = 0; i<n; i++)
    aux[i] = 0;
  
  for(int i = 0; i<n; i++)
    aux[comp[i]]++;

  int aux2[n];
  for(int i = 0; i<n; i++)
    aux2[i] = 0;
  
  for(int i=0; i<n; i++)
    aux2[aux[i]]++;

  cout << "Il y a " << aux2[1] << " points isolés" <<endl;
  for(int i = 2; i<n;i++)
    if(aux2[i] != 0)
      cout << "Il y a " << aux2[i] << " composantes de taille " << i << endl;
}


int main()
{ 
  int n;     // Nombre de sommets.	
  int m;     // Nombre d'aretes.	
  cout << "Entrer le nombre de sommets:";
  cin >> n;
  cout << "Entrer le nombre d'aretes:";
  cin >> m;
  int edge[m][2];    // Tableau des aretes.
  
  int comp[n]; // comp[i] est le numero de la composante contenant i.
  vector<int> L[n]; //liste des sommets de comp(x)
  int t[n]; // taille de comp(x)

  grapheRandom(n, m, edge);
  composante(n, m, edge, comp, L, t);

  ecritureTailles(n, m, comp);

  /*
  for(int i =0; i<m; i++){
    cout << edge[i][0] << ","<< edge [i][1] <<endl;
  }
  
  cout << endl;
  for(int k = 0;k<n;k++){
    if(comp[k].empty() == 0){
      cout << k << " : " ;
      for(int l =0;l<comp[k].size();l++)
	cout << comp[k][l] << ",";
      cout << "\n";
    }
  }
   
  
    
  for(int k = 0; k<n;k++)
    cout << k << " -> " << comp[k] << endl;
  */
  
  return EXIT_SUCCESS;
}
