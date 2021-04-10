#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;
typedef struct coord{int abs; int ord;} coord;

void pointRandom(int n, coord point[]){
  srand(time(NULL));
  for(int i =0; i<n; i++){
    point[i].abs = rand()%613;
    point[i].ord = rand()%792;
  }
}

void distance(int n,int m, coord point[], int edge[][3]){
  int i =0, j=1;
  for(int k =0; k<m;k++){
    edge[k][0] = i;
    edge[k][1] = j;
    edge[k][2] = ( pow((point[i].abs - point[j].abs),2) + pow((point[i].ord - point[j].ord),2));
    j++;
    if(j>=n){
      i++;
      j = i+1;
    }
  }
}

int compare(const void * a,const void * b)
{
  return ((int*)a)[2] - ((int*)b)[2];
}

void tri(int m, int edge[][3])
{
  qsort(edge,m,sizeof(edge[0]),compare);
}

int Union(int n, int TA, int arbre[][2], int edge[2]){

  if(TA +1 > n-1)
    return TA;

  bool present = false;
  for(int i =0; i<TA;i++){
    if(arbre[i][0] == edge[0] && arbre[i][1] == edge[1])
      present = true;
  }
  if(!present){
      arbre[TA][0] = edge[0];
      arbre[TA][1] = edge[1];
      return ++TA;
  }else
    return TA;
  
}

void kruskal(int n, int m, int edge[][3], int arbre[][2]){
  int TA = 0;
  int comp[n];
  vector<int> L[n]; //liste des sommets de comp(x)
  int t[n]; // taille de comp(x)
  
  for(int i =0;i<n;i++){
    comp[i] = i;    
    L[comp[i]].push_back(i);
    t[comp[i]] = 1;
  }
  
  int aux, e;
    for(int i = 0; i<m; i++){
    if(comp[edge[i][0]] != comp[edge[i][1]]){
      if(t[comp[edge[i][0]]] > t[comp[edge[i][1]]]){
	e = edge[i][0];
	edge[i][0] = edge[i][1];
	edge[i][1] = e;
      }
      aux = comp[edge[i][0]];
      TA = Union(n, TA, arbre, edge[i]);
      t[comp[edge[i][1]]] = t[comp[edge[i][1]]] + t[aux];
      while(L[aux].empty() == 0){
	comp[L[aux].back()] = comp[edge[i][1]];
	L[comp[edge[i][1]]].push_back(L[aux].back());
	L[aux].pop_back();
      }
    }
  }
}

void affichageGraphique(int n, coord point[], int arbre[][2])
// Cree le fichier Exemple.ps qui affiche
// les points et l'arbre de Kruskal.
{
  ofstream output;                           
  output.open("Exemple.ps",ios::out);
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
  for(int i=0;i<n-1;i++)
   {
     output << point[arbre[i][0]].abs << " " << point[arbre[i][0]].ord 
	    << " moveto" << endl;
     output << point[arbre[i][1]].abs << " " << point[arbre[i][1]].ord
	    << " lineto" << endl;
     output << "stroke" << endl;
     output << endl;
   }
  output << "showpage";
  output << endl;
}


int main(){
  int n;             //Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n;
  int m=n*(n-1)/2;   // Le nombre de paires de points.
  coord point[n];    // Les coordonnees des points dans le plan.
  int edge[m][3];    // Les paires de points et le carre de leur longueur.
  int arbre[n-1][2]; // Les aretes de l'arbre de Kruskal. 

  pointRandom(n, point);
  distance(n, m, point, edge);
  tri(m, edge);
  kruskal(n, m, edge, arbre);
  affichageGraphique(n, point, arbre);

  /*
  for(int i = 0;i<n;i++)
    cout << "point " << i << " : " << point[i].abs << "," << point[i].ord << endl;

  cout << endl;
  
  for(int i = 0; i<m; i++)
    cout << "arete " << i << " : " << edge[i][0] << "-" << edge[i][1] << "  d^2 = " << edge[i][2] << endl;

  cout << endl;
  cout << "arbre : " << endl;
  
  for(int i =0; i<n-1;i++)
    cout << i << " : " << arbre[i][0] << "-" << arbre[i][1] << endl;
  */
  return EXIT_SUCCESS;
}
