#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

const int N=1400;
const int M=(N*(N-1))/2;
  
typedef struct coord{int abs; int ord;} coord;

void pointRandom(int n,coord point[]){
  // srand(time(NULL));
  for(int i =0; i<n; i++){
    point[i].abs = rand()%613;
    point[i].ord = rand()%792;
  }
}

float distance(coord p1,coord p2){
  return ( pow((p1.abs - p2.abs),2) + pow((p1.ord - p2.ord),2));
}

void voisins(int n,int dmax,coord point[],vector<int> voisin[],int &m){

  m = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i!=j && distance(point[i], point[j]) <= pow(dmax,2))
      {
          voisin[i].push_back(j);
          m++;
      } 
    } 
  }
}

void voisins2arete(int n,vector<int>voisins[],int arete[][2]){
  int k = 0;
  for (int i = 0; i < n; i++)
  {
    for (size_t j = 0; j < voisins[i].size(); j++)
    {
      arete[k][0] = i;
      arete[k][1] = voisins[i][j];
      k++;
    }
  }
}
void affichageGraphique(int n,int m,coord point[],int arete[][2],string name)
{
  ofstream output;                           
  output.open(name+".ps",ios::out);
  output << "%!PS-Adobe-3.0" << endl;
  output << "%%BoundingBox: 0 0 612 792" << endl;
  output << endl;  
  for(int i=0;i<n;i++)
    {
      output << point[i].abs << " " << point[i].ord << " 3 0 360 arc" <<endl;
      output << "0 setgray" <<endl;
      output << "fill" <<endl;
      output << "stroke"<<endl;
      output << endl;
    }
  output << endl;
  for(int i=0;i<m;i++)
   {
     output << point[arete[i][0]].abs << " " << point[arete[i][0]].ord 
	    << " moveto" << endl;
     output << point[arete[i][1]].abs << " " << point[arete[i][1]].ord
	    << " lineto" << endl;
     output << "stroke" << endl;
     output << endl;
   }
  output << "showpage";
  output << endl;
}

bool existe(int n,int dis[],bool traite[],int &x){
  bool res = false;
  for (int i = 0; i < n; i++)
  {
    if(!traite[i]){
      res = true;
      if(x == -1)
        x=i;
      else if(dis[x] > dis[i])
        x = i;
    }
  }
  return res;
}
void dijkstra(int n,vector<int> voisin[],coord point[],int pere[]){

  bool traite[n];
  int d[n];
  for (int i = 0; i < n; i++)
  {
    d[i] = (int) INFINITY;
    traite[i] = false;
    pere[i] = -1;
  }
  pere[0] = 0; d[0] = 0;
  int x = 0;int y;
  while(existe(n, d, traite, x)){
    traite[x] = true;
    for (size_t i = 0; i < voisin[x].size(); i++)
    {
      y = voisin[x][i];
      if(!traite[y] && d[y] > d[x]+distance(point[x], point[y])){
        d[y] = d[x]+distance(point[x], point[y]);
        pere[y] = x;
      }
    }
    x = -1; 
  }
}

int construireArbre(int n,int arbre[][2],int pere[]){
  int k = 0;
  for (int i = 0; i < n; i++)
  {
    if(pere[i] != -1){
      arbre[k][0] = i;
      arbre[k][1] = pere[i];
      k++;
    }
  }
  return k;
}

int main()
{
  int n;                           // Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n; 
  int dmax=50;                     // La distance jusqu'a laquelle on relie deux points.
  coord point[N];                  // Les coordonnees des points.
  vector<int> voisin[N];           // Les listes de voisins.          
  int arbre[N-1][2];               // Les aretes de l'arbre de Dijkstra.
  int pere[N];                     // La relation de filiation de l'arbre de Dijkstra.
  int m;                           // Le nombre d'aretes

  pointRandom(n, point);
  voisins(n, dmax, point, voisin, m);

  int arete[m][2];                 // Les aretes du graphe
  voisins2arete(n, voisin, arete);
  affichageGraphique(n,m,point, arete, "Graphe");

  dijkstra(n,voisin,point,pere);

  int k = construireArbre(n,arbre,pere);
  affichageGraphique(n,k,point, arbre, "Arbre");

  return EXIT_SUCCESS;
}
