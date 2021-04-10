#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
using namespace std;

//  DERNIERLSC ET ESTTRIEELSC 
// Res : Renvoie l'adresse de la derniere cellule de la liste non vide L 
ListeSC dernierLSC(ListeSC L){
  assert(L != NULL);
  while(L->succ!=NULL){
    L = L->succ;
  }
  return L;
}

//   Res : Renvoie 1 si L est une ListeSC triee, 0 sinon 
bool estTrieeLSC(ListeSC L){
  while(L->succ!=NULL){
    if(L->info>L->succ->info){
      return false;
    }
    L = L->succ;
  }
  return true;
}


//  OTERREPETITION 
//    Res : Supprime de la ListeSC L tous les elements consecutifs egaux 
//          Opere en modifiant le chainage de la ListeSC L 
// version iterative 
void oterRepetitionLSC(ListeSC L){
  while(L->succ!=NULL){
    if(L->info==L->succ->info){
      L->succ = L->succ->succ;
    }else{
      L = L->succ;
    }
  }
  return;
}

//    Res : Supprime de la ListeSC L tous les elements consecutifs egaux 
//          Opere en modifiant le chainage de la ListeSC L 
//    version recursive 
void oterRepetitionLSCR(ListeSC L){
  if(L->succ==NULL) return;
  if(L->info==L->succ->info){
    L->succ = L->succ->succ;
    return oterRepetitionLSCR(L);
  }
    return oterRepetitionLSCR(L->succ);
}


//   CONCATENATION DE 2 LISTES  
//   Res : Modifie la liste L1 en la concatenant avec la liste l2 
//         Opere en modifiant le chainage de la listeSC L1 
//   Version utilisant la fonction dernierLSC 
void concatLSC(ListeSC& L1,ListeSC L2){
  dernierLSC(L1)->succ=L2;
}

//   Res : Renvoie la ListeSC obtenue par concatenation des ListeSC L1 et L2 
//         Opere en recopiant les elements des 2 listeSC L1 et L2 
//   complexite : ??? 
ListeSC concatLSCCopie(ListeSC L1,ListeSC L2){
  ListeSC L = NULL;
  while(L1!=NULL){
    insererFinLSC(L,L1->info);
    L1=L1->succ;
  }
  while(L2!=NULL){
    insererFinLSC(L,L2->info);
    L2=L2->succ;
  }
  return L;
}


