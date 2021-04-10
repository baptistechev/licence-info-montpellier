#include <iostream>
#include <vector>

using namespace std;

const int N=5;
const int INF=9999;                      //La valeur infinie.    

void floydWarshall(int longueur[][N],int dist[][N],int chemin[][N]){
  for (int i = 0; i < N; i++)
  {
    dist[i][i] = 0; chemin[i][i] = i;
    for (int j = 0; j < N; j++)
    {
      if(longueur[i][j]!=INF){
        dist[i][j] = longueur[i][j]; 
        chemin[i][j] = j;
      }        
      else{
        dist[i][j] = INF;
        chemin[i][j] = -1;
      }
    }
  }

  for (int k = 0; k < N; k++)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (dist[i][j] > dist[i][k] + dist[k][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];
          chemin[i][j] = chemin[i][k];
        }
      }
    }
  }

  for (int i = 0; i < N; i++)
  {
    if(dist[i][i] < 0)
      cout << "Arc de poids < 0" << endl;
  }
  
}

void affichage(int dist[][N],int chemin[][N]){
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << dist[i][j] << "   ";
    }
    cout << endl;
  }

  cout << endl << endl;
  
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << chemin[i][j] << "   ";
    }
    cout << endl;
  }
}

void itineraire(int i,int j,int chemin[][N]){

  cout << endl << "L'itineraire est : " << i << " ";

  int k = i;
  while((k = chemin[k][j]) != j){
    cout << k << " ";
  }

  cout << k << endl;
    
}

int main()
{

  int longueur[N][N]={{0,2,INF,4,INF},   //Les longueurs des arcs.
		      {INF,0,2,INF,INF}, //longueur[i][j]=INF si l'arc ij n'existe pas
		      {INF,INF,0,2,INF},
		      {INF,-3,INF,0,2},
		      {2,INF,INF,INF,0}};                
  int dist[N][N];                        //Le tableau des distances.
  int chemin[N][N];                      //Le tableau de la premiere etape du chemin de i a j.
  floydWarshall(longueur,dist,chemin);
  affichage(dist,chemin);  


  int d, a;
  cout << "Entrez le depart : "; 
  cin >> d;
  cout << endl << "Entrez l'arrivee : "; 
  cin >> a;

  itineraire(d, a,chemin);

  return EXIT_SUCCESS;
}
