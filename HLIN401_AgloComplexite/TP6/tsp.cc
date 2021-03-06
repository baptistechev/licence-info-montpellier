#include <iostream>
#include <sstream>
#include <math.h>
#include <cfloat>
#include <algorithm>

#include "ensembles.h"
#include "matrice.h"
#include "points.h"

using namespace std;

float distance(coord& p1, coord& p2)
{
  return sqrt(pow(p1.x - p2.x,2)+pow(p1.y-p2.y,2));
}

float arrondi(float x){ // arrondi au dixième
  return (round(x*10)/10);
}

float tsp(int n, coord* P, float** D, int** Prec, int& min)
{
  // n nombre de points 
  // P tableau de points
  // D Matrice des distances : a remplir

  D[vide()][n-1] = 0.;

  for (int s = 1; s < n; s++) // taille des ensembles
  {
    ensemble U = plein(s);
    while (U)
    {
      //      cout << U << " : " << str(U) << endl;
      D[U][n-1] = FLT_MAX;
      
      for(int j = 0;j<n-1;j++){
	if(appartient(U,j)){

	  for(int i = 0;i<n;i++){
	    if(i!=j){
	      //D[U][j] = std::min(D[suppr(U,j)][i] + distance(P[i],P[j]),D[U][j]);
	      if(arrondi(D[suppr(U,j)][i] + distance(P[i],P[j])) <= arrondi(D[U][j])){
		D[U][j] = D[suppr(U,j)][i] + distance(P[i],P[j]);
		Prec[U][j] = (i==n-1)? 0 : i;
	      }
	    }
	  }
	  
	}
      }

      U = suivant(U, n-1, s);
    }
  }


  float res = FLT_MAX;

  for(int j = 0;j<n-1;j++){
    //cout << D[plein(n-1)][j] + distance(P[j],P[n-1]) << "  " ;

    if( arrondi(D[plein(n-1)][j] + distance(P[j],P[n-1])) <= arrondi(res)){
      res = D[plein(n-1)][j] + distance(P[j],P[n-1]);
      min = j;
    }
  }
  
  return res;
}

void tsp_rec(int* circuit, int n, float** D, int** Prec, int min)
{
  circuit[0] = n-1;
  circuit[1] = min;
  ensemble U = plein(n-1);

  for(int k = 2;k<n;k++){
    //    cout << Prec[U][circuit[k-1]] << endl;
    circuit[k] = Prec[U][circuit[k-1]];
    U = suppr(U,circuit[k-1]);
  }
  
}

float tsp_bruteforce(int n, coord* P)
{
  return 0.; // A modifier
}


