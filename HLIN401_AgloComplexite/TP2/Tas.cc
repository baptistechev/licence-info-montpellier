#include <iostream>
#include "Tas.h"

using namespace std;


// ====================
//  TAS ET TRI PAR TAS
// ====================

void afficher(int n, int* T)
{
  for(int i = 0; i<n; i++){
    cout << T[i] << " ";
  }
} 

bool estTasMax(int n, int* T)
{
  for(int i = 1; i < n; i++){
    if( T[(i-1)/2] < T[i] ){
      return false;
    }
  }
  return true;
}

bool estTasMin(int n, int* T)
{
  for(int i = 1; i < n; i++){
    if( T[(i-1)/2] > T[i] ){
      return false;
    }
  }
  return true;
}

void tableauManuel(int n, int* T)
{
  for(int i = 0; i<n ; i++){
    cin >> T[i];
  }
}

void tableauAleatoire(int n, int* T, int m, int M)
{
  for(int i = 0; i<n ; i++){
    T[i] =( rand() % (M-m) ) + m;
  }
}

#define Pere(i) ((i-1)/2)
#define FilsG(i) (2*i+1)
#define FilsD(i) (2*i+2)

void entasser(int n, int* T, int i)
{
  int m = i, g = FilsG(i), d = FilsD(i);
  if(g<n && T[g]>T[m]) m=g;
  if(d<n && T[d]>T[m]) m=d;
  if(m!=i){
    int sav = T[i];
    T[i] = T[m];
    T[m] = sav;
    entasser(n,T,m);
  }
}

void tas(int n, int* T)
{
  for(int i = (n/2)-1; i>=0; i--){
    entasser(n,T,i);
  }
}

int* trier(int n, int* T)
{
  int* Ttrie = new int[n];
  tas(n,T);
  for(int i= n-1; i>=0;i--){
    Ttrie[i] = T[0];
    T[0]=0;
    tas(n,T);
  }
  return Ttrie;
}

void trierSurPlace(int n, int* T)
{
  int N = n;
  int sav;

  while(N>=0){
    tas(N,T);
    sav = T[N-1];
    T[N-1] = T[0];
    T[0]=sav;
    N--;
  }
}

