#include <cstdlib>
#include <iostream>
#include "TrisRang.h"
#include <math.h>

using namespace std;

void fusion(int n1, int n2, int* T1, int* T2, int* T)
{
  int i=0, j=0, k=0;
  while(i<n1 && j<n2 && k<n1+n2){

    if(T1[i]<T2[j]){
      T[k] = T1[i];
      i++;
    }else if(T1[i]>T2[j]){
      T[k] = T2[j];
      j++;
    }else{
      T[k] = T1[i];
      i++;
    }
    k++;
  }

  for(int i2=i;i2<n1;i2++){
    T[k] = T1[i2];
    k++;
  }
  for(int j2=j;j2<n2;j2++){
    T[k] = T2[j2];
    k++;
  }

}

void trifusion(int n, int* T)
{
  if(n==1){
    return;
  }else{
    int n1 = floor(n/2);
    int* T1 = new int[n1];
    for(int i=0;i<n1;i++){
      T1[i] = T[i];
    }

    int* T2 = new int[n-n1];
    for(int i=n1;i<n;i++){
      T2[i-n1] = T[i];
    }
    
    trifusion(n1,T1);
    trifusion(n-n1,T2);
    fusion(n1,n-n1,T1,T2,T);
    delete[] T1;
    delete[] T2;
  }
}

int choixPivot(int n, int* T, pivot P) 
{
  switch (P)
  {
    case FIXE:
      return T[0];
      break;
    case ALEATOIRE:
      return T[rand() % n];
      break;
  }
}

int rang(int k, int n, int* T, pivot P)
{
  if(n==1) return T[0];
  int p = choixPivot(n,T,P);
  int Ninf=0, Neq=0;
  for(int i=0;i<n;i++){
    if(T[i]<p)
      Ninf++;
    else if(T[i]==p)
      Neq++;
  }
  if(k<=Ninf){
    int* Tinf = new int[Ninf];
    int j =0;
    for(int i=0;i<n;i++){
      if(T[i]<p){
	Tinf[j] = T[i];
	j++;
      }
    }
    return rang(k,Ninf,Tinf,P);
  }else if(Ninf<k && k<=Ninf+Neq){
    return p;
  }else{
    int* Tsup = new int[n-Ninf-Neq];
    int j =0;
    for(int i =0;i<n;i++){
      if(T[i]>p){
	Tsup[j] = T[i];
	j++;
      }
    }
    return rang(k-Ninf-Neq,n-Ninf-Neq,Tsup,P);
  }
}

void trirapide(int n, int* T, pivot P)
{
  // A compléter
}

