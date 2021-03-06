#include <iostream>
#include <fstream>
#include <stdlib.h>  // pour rand
#include <assert.h>
#include "outilsTab5.h"

using namespace std;



int* copieTab(int* T, int t){
  int* Tc;
  Tc=new int[t];
  for( int i=0;i<t;i++)Tc[i]=T[i];
  return Tc;
}

int* genTab(int n){
    int* T; 
    T=new int[n];
    for (int i=0;i<n;i++) T[i]=rand();
    return T;
}

void afficheTab(int* T,	int taille){
  cout << "\n[ ";
  for (int i=0;i<taille;i++) cout << T[i] << " ";
  cout << "]\n";
}

void echanger(int& a, int& b){int aux=a; a=b; b=aux; return;}

void fichierTemps(const char *  nomFic, int tMaxTab, int pas, void (*fTri)(int*,int))
{
    int taille;
    int* Tab;
    clock_t t1, t2;    
    ofstream fichier(nomFic,ios::out);

    if (fichier)
    {
        for (taille=pas; taille<=tMaxTab; taille=taille+pas){
            Tab=genTab(taille);
            t1=clock();
            (*fTri)(Tab,taille);
            t2=clock();
            fichier << taille <<" "<< (double)(t2-t1)/ CLOCKS_PER_SEC << endl;
        }
        fichier.close();
    }
    else cerr << " Problème ouverture fichier"<< endl;

    return ;
}



/* ********************** Les Tris *********************** */

/* Tri par insertion */
void triInsertion(int* T, int taille)
{
  int j,dmp;
  for(int i=1;i<taille;i++){
    j = i;
    while(T[j]<T[j-1]){
      dmp = T[j];
      T[j]=T[j-1];
      T[j-1] = dmp;
      j--;
    }
  }


  return;
}




/* Tri par Sélection */
void triSelection(int* T, int taille)
{
  int min,idmin;
  for(int i=0 ; i<taille-1; i++){
    min = T[i];
    idmin = i;
    for(int j=i; j<taille; j++){
      if(T[j]<min){
	min=T[j];
	idmin = j;
      }
    }
    T[idmin] = T[i];
    T[i] = min;

  }

  return;
}




/* Tri par Tas */
int filsMax(int* T, int i, int iMax)
{
  if ((i*2+2>iMax) || (T[2*i+1]>T[2*i+2])) return 2*i+1;
  else return 2*i+2;
}
void triParTas(int* T, int taille)
{
  int i,j,k; 
  for (i=1;i<taille;i++){
    j=i;
    while(j>0 && T[(j-1)/2]<T[j]){
      echanger(T[j],T[(j-1)/2]);
      j=(j-1)/2;}}
  for (i=taille-1;i>0;i--){
    echanger(T[0],T[i]);
    j=0;
    while( (2*j+1<i) && T[filsMax(T,j,i-1)]>T[j]){
      k=filsMax(T,j,i-1);
      echanger(T[j],T[k]);
      j=k;} }
  return;
}





/* Tri Rapide */
void triRapInd1(int* T, int deb, int fin)
/* trie le sous-tableau T[g..d] selon le tri rapide */
{
   if(deb>=fin) return;
  int d = deb, f = fin, piv = (deb+fin)/2;
  int sav;
  while(d<f){
    while((d<piv) && (T[d]<=T[piv])){
      d++;
    }
    while((f>piv) && (T[f]>=T[piv])){
      f--;
    }
    sav = T[d];
    T[d] = T[f];
    T[f] = sav;
    
    if(piv == d){
      piv = f;
    }else if(piv == f){
      piv =d;
    }
  }
  triRapInd1(T,deb,piv-1);
  triRapInd1(T,piv+1,fin);
  
  return;
}

void triRapide1(int* T, int taille)
{
  triRapInd1(T,0,taille-1);
  return;
}




/* tri par Fusion */
void triFusionBis(int* T, int g, int d)
/* trie le sous-tableau T[g..d] par fusion */
{
  int m;
  int taille = (int) d-g+1;
  if(taille>1){
    m = g + (taille/2);
    triFusionBis(T,g,m-1);
    triFusionBis(T,m,d);

    int* T2 = new int[taille];
    int i=g,j=m,k=0;
    cout << taille << endl;
    afficheTab(T,taille);
    afficheTab(T2,taille);
    while(i<m-g && j<taille){
      if(T[i]<T[j]){
	T2[k]=T[i];
	i++;
      }else{
	T2[k]=T[j];
	j++;
      }
      k++;
    }
    while(i<m-g){
      T2[k]=T[i];
      i++;k++;
    }
    while(j<taille){
      T2[k]=T[j];
      j++;k++;
    }
    afficheTab(T,taille);
    afficheTab(T2,taille);
    for(int z=0;z<taille;z++){
      T[g+z]=T2[z];
    }
    delete[] T2;
  }
}
void triFusion(int* T, int taille)
{
  return;
}
 






/* Nombre de valeurs différentes dans un tableau */
int nbValDiff(int T[], int taille)
// Complexité : ?????
{
  int* T2 = new int[taille];
  T2[0]=T[0];
  int tailleT2=1,i=1;
  bool a;
  while(i<taille){
    a=false;
    for(int j=0;j<tailleT2;j++){
      if(T[i]==T2[j]){
	i++;
	a=true;
	break;
      }
    }
    if(!a){
      T2[tailleT2]=T[i];
      tailleT2++;
    }
  }

  return tailleT2;
  
}
