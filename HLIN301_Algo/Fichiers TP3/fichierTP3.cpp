#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
#include "fichierTP3.h"
using namespace std;



bool estTrieeLSC(ListeSC L){
  //   Res : Renvoie true si L est une ListeSC triée, false sinon 
  if (estVideLSC(L) || estVideLSC(L->succ))
    return true;
  else
    return (L->info < (L->succ)->info) &&  estTrieeLSC(L->succ);
}

bool estListeIntervalle(ListeSC L){
  //   Res : renvoie true si L est une Liste intervalle, renvoie false sinon 
  if(estTrieeLSC(L)){
    while(L->succ!=NULL){
      if(L->info!=L->succ->info-1){
	return false;
      }
      L=L->succ;
    }
    return true;
  }
  return false;
}

ListeSC consListeIntervalle1(int l, int p){
  //     Donnée : l entier positif
  //     Res : renvoie une liste intervalle de longueur l et dont le premier élément a pour valeur p 
  //     Complexité : O(l²)
  assert(l>=0);
  
  int i; ListeSC L;
  L=NULL;
  for(i=0;i<l;i++)    
    insererFinLSC(L,p+i);
  return L;
}

ListeSC consListeIntervalle2(int l, int p){
  //     Donnée : l entier positif
  //     Res : renvoie une liste intervalle de longueur l et dont le premier élément a pour valeur p 
  //     Complexité : O(l)
  // 

  assert(l>=0);
  ListeSC L = NULL;
  while(l){
    L = creerLSC(p+l-1,L);
    l--;
  }  
  return L;
}

ListeSC consListeIntervalle3(int l, int p){
  //     Donnée : l entier positif
  //     Res : renvoie une liste intervalle de longueur l et dont le premier élément a pour valeur p 
  //     Complexité : O(l)  
  //     Version récursive

  assert(l>=0);
  if(l>1){
    return creerLSC(p,consListeIntervalle3(l-1,p+1));
  }else{
    return creerLSC(p,NULL);
  }
}

// Temps de construction d'une liste intervalle de taille 50000 :
// avec consListeIntervalle1 : 6.28148
// avec consListeIntervalle2 : 0.001417 
// avec consListeIntervalle3 : 0.001512 

void transfListeIntervalle(ListeSC L){
  //     Donnée : L est une liste triée non vide  
  //     Res : modifie L en y inserant des éléments de sorte qu'elle soit une Liste Intervalle
  //     Complexité : O(l) avec l longueur de L
  assert((L!=NULL));
  assert(estTrieeLSC(L));

  while(L->succ != NULL){
    if(L->info!=L->succ->info -1){
      insererApresLSC(L,L,L->info+1);
    }
    L = L->succ;
  }
  return;
}

ListeSC intersectionListesIntervalles(ListeSC l1, ListeSC l2){
  //     Donnée : l1 et l2 2 listes intervalles
  //     Res : Renvoie l'intersection de l1 et l2; les éléments de la liste résultat sont recopiés
  //     Complexité : lineaire
  assert(estListeIntervalle(l1));
  assert(estListeIntervalle(l2));
  
  ListeSC l3 = NULL;
  while(l1!=NULL && l2!=NULL){
    if(l1->info > l2->info){
      l2=l2->succ;
    }else if(l1->info < l2->info){
      l1=l1->succ;
    }else{ //egal
      insererFinLSC(l3,l1->info);
      l1=l1->succ;
      l2=l2->succ;
    }
  }
  return l3;
}
  
void plusLgSsLiInterv(ListeSC &L){
  //     Donnée : L liste
  //     Res : L est modifiee, elle est la plus longue sous-liste intervalle de la liste en entrée
  //     Complexité : ????

  ListeSC P = NULL,Q=NULL;
  int taille = 0,tailleM=0;
  while(L->succ !=NULL){
    P=NULL;
    taille=0;
    while(L->succ != NULL && L->info == L->succ->info-1){
      insererFinLSC(P,L->info);
      taille++;
      L=L->succ;
    }
    insererFinLSC(P,L->info);
    if(taille>tailleM){
      Q=P;
      tailleM=taille;
    }
    if(L->succ!=NULL){
      L=L->succ;
    }
  }
  L=Q;
}





