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

void composante(int n, int m, int edge[][2], int Ncomp[], vector<int> comp[]){
  for(int k = 0;k<n;k++){
    comp[k].push_back(k);
    Ncomp[k] = k;
  }

  int aux, pasaux, link;
  for(int i =0; i<m;i++){
    if(Ncomp[edge[i][0]] != Ncomp[edge[i][1]]){
      pasaux = Ncomp[edge[i][0]];
      aux = Ncomp[edge[i][1]];
      if(pasaux > aux){
	link = pasaux;
	pasaux = aux;
	aux = link;
      }      
      while(comp[aux].empty() == 0){
	comp[pasaux].push_back(comp[aux].back());
	Ncomp[comp[aux].back()] = pasaux;	
	comp[aux].pop_back();
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
  int Ncomp[n]; // comp[i] est le numero de la composante contenant i.
  vector<int> comp[n];       

  grapheRandom(n, m, edge);
  composante(n, m, edge, Ncomp, comp);

  ecritureTailles(n, m, Ncomp);

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
