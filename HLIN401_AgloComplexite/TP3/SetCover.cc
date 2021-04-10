#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

#include "AffichageMaisons.h"

#define dcouv 100

#define distance2(x,y) ((x[0]-y[0])*(x[0]-y[0])) + ((x[1]-y[1])*(x[1]-y[1]))

bool Couvre(int i, int j, const int coordMaisons[][2])
{
  if(distance2(coordMaisons[i],coordMaisons[j])<dcouv*dcouv)
    return true;
  else
    return false;
}

int ChoixProchaineMaison(int n, const int coordMaisons[][2], const bool dejaCouvertes[])
{  
  int nbMaisonCouvertes[n];
  for(int i = 0;i<n;i++){
    nbMaisonCouvertes[i] = 0;
  }
  
  for(int i = 0;i<n;i++){
    if(!dejaCouvertes[i]){
      for(int j = 0;j<n;j++){
	if(i!=j && !dejaCouvertes[j] && Couvre(i,j,coordMaisons))
	  nbMaisonCouvertes[i]++;
      }
    }
  }
  
  int max = -1, idMax = 0;
  for(int i = 0;i<n;i++){
    if(nbMaisonCouvertes[i]>max && !dejaCouvertes[i]){
      max = nbMaisonCouvertes[i];
      idMax = i;
    }
  }
  
  return idMax;
}

int ChoixEmetteurs(int n, const int coordMaisons[][2], bool emetteurs[])
{
  int cpt = 0;

  bool dejaCouvertes[n];
  for(int i = 0;i<n;i++) dejaCouvertes[i] = false;
  bool all = false;
  
  while(!all){
    emetteurs[ChoixProchaineMaison(n,coordMaisons,dejaCouvertes)]=true;
    cpt++;

    all = true;
    
    for(int i = 0;i<n;i++){
      if(emetteurs[i]){
	dejaCouvertes[i] = true;
	for(int j = 0;j<n;j++){
	  if(i!=j && Couvre(i,j,coordMaisons)){
	    dejaCouvertes[j]=true;
	  }
	}
      }
    }

    for(int i = 0;i<n;i++) all = all && dejaCouvertes[i];
    
  }
  
  return cpt;
}

bool isAllCovert(const int coordMaisons[][2], int n,bool emetteurs[]){

  bool dejaCouvertes[n];
  for(int i = 0;i<n;i++) dejaCouvertes[i] = false;
    
    for(int i = 0;i<n;i++){
      if(emetteurs[i]){
	dejaCouvertes[i] = true;
	for(int j = 0;j<n;j++){
	  if(i!=j && Couvre(i,j,coordMaisons)){
	    dejaCouvertes[j]=true;
	  }
	}
      }
    }

    for(int i = 0;i<n;i++)
      if(!dejaCouvertes[i])
	return false;

    return true;
}

bool parcoursPos(int i, int nbAntenne, const int coordMaisons[][2], int n,bool emetteurs[]){
  if(nbAntenne != 0){
    for(int j = i; j<n;j++){
      emetteurs[j] = true;
      if(parcoursPos(j+1,nbAntenne-1,coordMaisons,n,emetteurs))
	return true;
      emetteurs[j] = false;
    }
    return false;
  }else{
    
    AffichageMaisonsEmetteurs(n, coordMaisons, emetteurs, "EmetteursOpt");
    usleep(600000);
    
    //check si tout est couvert
    return isAllCovert(coordMaisons, n,emetteurs);
  }
}

int ChoixEmetteursOpt(int n, const int coordMaisons[][2], bool emetteurs[])
{
  int k = 0;
  bool fini = false;

  while(!fini && k<=n){
    fini = parcoursPos(0,k,coordMaisons,n,emetteurs);
    k++;
  }
  return k-1;
}

#undef dcouv
